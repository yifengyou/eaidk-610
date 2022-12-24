import sys, time, signal
sys.path.append("../../../platform/source/speech")
import esp_record

filename = "rec.pcm"

def sigint_handler(signum, frame):
    global objRecord, loops
    objRecord.close()
    loops = 0
    print("exit sigint handle")
if __name__ == '__main__':
    global objRecord, loops
    signal.signal(signal.SIGINT, sigint_handler)
    f = open(filename, 'wb')
    objRecord = esp_record.espRecord()
    res = objRecord.init("MainMicCapture")
    print("init res: ", res)
    loops = 1000000
    while loops > 0:
        loops -= 1
        # Read data from device
        l, data = objRecord.getPCM()

        if l:
            f.write(data)
            time.sleep(.001)
    print("exit main program")

