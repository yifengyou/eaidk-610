import sys, time, signal
sys.path.append("../../../platform/source/speech")

import esp_alsaplay


filename = "voicebaidu.mp3"

def sigint_handler(signum, frame):
    global objPlay, exit
    exit = True

    objPlay.close()

    print("exit sigint handle")
    exit(0)

if __name__ == '__main__':
    global objPlay, loops, exit
    exit = False

    signal.signal(signal.SIGINT, sigint_handler)

    objPlay = esp_alsaplay.espPlayAlsa()
    objPlay.init()
    #objPlay.play(filename)
    objPlay.trans_mp3_to_wav(filename)
    objPlay.play()
    #time.sleep(5)
    objPlay.play("esp_demo.wav")

    '''
    while exit is False:
        if objPlay.getState() == -1:
            time.sleep(0.5)
            continue
        else:
            break
    '''

    m = input("press <ENTER> to exit:")

    print("going to exit")
    objPlay.close()

    print("exit main program")
