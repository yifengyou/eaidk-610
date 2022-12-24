import alsaaudio, syslog, os, time, pyaudio
from concurrent.futures import ThreadPoolExecutor
from pydub import AudioSegment
from sox import core
import subprocess
from subprocess import CalledProcessError

class espPlaySox(object):
    def __init__(self):
        self.pool_list = []
        self.exit = False
    def init(self):
        res = self.getDevice("Device")
        if res:
            self.device = "Device"
        else:
            self.device = "realtekrt5651co"
        self.threadPool = ThreadPoolExecutor(max_workers=1, thread_name_prefix="playsound_")


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
        '''
        args = ['play',   path]
        try:
            print("Executing: ", " ".join(args))
            process_handle = subprocess.Popen(
                args, stdout=subprocess.PIPE, stderr=subprocess.PIPE
            )

            status = process_handle.wait()
            if process_handle.stderr is not None:
                print(process_handle.stderr)

            if status is not 0:
                print("Play returned with error code ", status)
        except OSError as error_msg:
            print("OSError: Play failed! ", error_msg)
        except TypeError as error_msg:
            print("TypeError: ", error_msg)
        '''
        os.system('AUDIODEV=plughw:'+self.device+' play -q '+path)
        return 'finished'

    def play(self, path="play.wav"):
        if os.path.exists(path):
            f = self.threadPool.submit(self.playThread, path)
            self.pool_list.append(f)
            #self.threadPool.map(self.playThread, self.fd)
        else:
            print ("bad luck, filepath is invalid: ", path)

    def convert_pcm_to_wav(self, pcm_path, wav_path, channels, width, rate):
        with open(pcm_path, 'rb') as pcmfile:
            pcmdata = pcmfile.read()
        with wave.open(wav_path, 'wb') as wavfile:
            wavfile.setparams((channels, width, rate, 0, 'NONE', 'NONE'))
            wavfile.writeframes(pcmdata)

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
