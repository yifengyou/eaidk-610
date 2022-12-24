import alsaaudio, syslog

SAMPLE_RATE_8K = 8000
SAMPLE_RATE_16K = 16000
class espRecord(object):
    def init(self, devName = "Audio", channels = 1, expectedSampleRate = 8000, pcmFormat=alsaaudio.PCM_FORMAT_S16_LE):
        bRes = self.getDevice(devName)
        if(bRes == False):
            return -1
        if devName is "Audio":
            sDevice = "plughw:"+devName
        else:
            sDevice = devName
        self.inp = alsaaudio.PCM(alsaaudio.PCM_CAPTURE, 0, device=sDevice)
        if self.inp is None:
            return -2
        print("channels: ",channels)
        if self.inp.setchannels(channels) is None:
            self.inp.close()
            return -3
        if self.inp.setrate(expectedSampleRate) is None:
            self.inp.close()
            return -4
        if self.inp.setformat(pcmFormat) is None:
            self.inp.close()
            return -5
        frameSize = self.getFrameSize(expectedSampleRate)
        if self.inp.setperiodsize(frameSize) is None:
            self.inp.close()
            return -6
        return 0
    def getDevice(self, devName):
        if devName is "MainMicCapture":
            return True
        lst = alsaaudio.pcms(1)
        print("lst:",lst)
        print("type:", type(lst))
        for str_ in lst:
            num = str_.find("CARD=")
            sstr = str_[num+5:len(str_)]
            numb = sstr.find(",")
            rstr = sstr[0:numb]
            if("Audio" == rstr):
                print("found the device")
                return True
        return False
    def getFrameSize(self, expectedSampleRate):
        if(expectedSampleRate == SAMPLE_RATE_8K):
            return 480
        elif(expectedSampleRate == SAMPLE_RATE_16K):
            return 960
        else:
            return -1
    def getPCM(self):
        l, data = self.inp.read()
        return l, data
    def close(self):
        self.inp.close()

