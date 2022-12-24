import alsaaudio, syslog, os, time, pyaudio
from concurrent.futures import ThreadPoolExecutor
from pydub import AudioSegment

class espPlayAlsa(object):
    def __init__(self):
        self.pool_list = []
        self.out = None
        self.exit = False
    def init(self):
        res = self.getDevice("Device")
        if res:
            self.device = "Device"
        else:
            self.device = "realtekrt5651co"
        self.threadPool = ThreadPoolExecutor(max_workers=1, thread_name_prefix="playsound_")
        self.p = pyaudio.PyAudio()

    def openPCM(self, channel=1, rate=44100, fmt=alsaaudio.PCM_FORMAT_S16_LE):
        self.out = alsaaudio.PCM(alsaaudio.PCM_PLAYBACK, device="plughw:"+self.device)
        if self.out is None:
            return -1
        if self.out.setchannels(channel) is None:
            self.out.close()
            return -2
        if self.out.setrate(rate) is None:
            self.out.close()
            return -3
        if self.out.setformat(alsaaudio.PCM_FORMAT_S16_LE) is None:
            self.out.close()
            return -4
        if self.out.setperiodsize(160) is None:
            self.out.close()
            return -5
        return 0

    def closePCM(self):
        if self.out:
            self.out.close()
            self.out = None
            time.sleep(0.1)

    def getDevice(self, devName):
        lst = alsaaudio.pcms(0)
        print("lst:",lst)
        print("type:", type(lst))
        for str_ in lst:
            num = str_.find("CARD=")
            sstr = str_[num+5:len(str_)]
            numb = sstr.find(",")
            rstr = sstr[0:numb]
            res = rstr.find(devName)
            if(-1 != res):
                print("found the device")
                return True
        return False

    def playThread(self, path):
        song = AudioSegment.from_wav(path)
        if self.out:
            self.out.close()
        res = self.openPCM(song.channels, song.frame_rate, self.p.get_format_from_width(song.sample_width))
        if res is not 0:
            print("open PCM device failed")
            return 'finished'
        self.fd = open(path, 'rb')
        if self.fd is -1:
            print("open failed, path:", path)
            return 'finished'
        data = self.fd.read(320)
        while data and self.exit is False:
            try:
                self.out.write(data)
                data = self.fd.read(320)
            except alsaaudio.ALSAAudioError as e:
                print('except:', e)
                break
        self.closePCM()
        self.fd.close()
        return 'finished'

    def play(self, path="play.wav"):
        if os.path.exists(path):
            f = self.threadPool.submit(self.playThread, path)
            self.pool_list.append(f)
            #self.threadPool.map(self.playThread, self.fd)
        else:
            print ("bad luck, filepath is invalid: ", path)

    def trans_mp3_to_wav(self, filePath, exportPath="play.wav"):
        self.song = AudioSegment.from_mp3(filePath)
        self.song.export(exportPath, format="wav")
    def getState(self):
        for item in self.pool_list:
            if item.result() is not 'finished':
                return -1
        return 0

    def close(self):
        self.exit = True
        self.threadPool.shutdown(wait=False)
        for item in self.pool_list:
            item.cancel()
        '''
        if self.out:
            print("close pcm device")
            self.out.close()
        '''
        if self.fd:
            print("close fd")
            self.fd.close()
