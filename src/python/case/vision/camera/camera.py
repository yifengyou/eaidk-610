import sys, time, signal
sys.path.append("../../../platform/source/vision")
import esp_camera
sys.path.append("../../../platform/source/common")
import esp_json

from esp_json import ESP_JSON_getJsonValue

def sigint_handler_usb(signum, frame):
    global objUSBCamera, loops
    objUSBCamera.stopCamera()
    print("exit sigint handle")

def sigint_handler_ipc(signum, frame):
    global objIpcCamera, loops
    objIpcCamera.stopCamera()
    print("exit sigint handle")

def sigint_handler_mipi(signum, frame):
    global objMipiCamera, loops
    objMipiCamera.stopCamera()
    print("exit sigint handle")

if __name__ == '__main__':
    global objUSBCamera, objIpcCamera, objMipiCamera

    cameraType = ESP_JSON_getJsonValue("CameraType")

    if (cameraType == "USB"):
        signal.signal(signal.SIGINT, sigint_handler_usb)

        objUSBCamera = esp_camera.espUsbCamera()
        res = objUSBCamera.init()
        print("init res: ", res)
        objUSBCamera.startCamera()
        objUSBCamera.stopCamera()
    elif (cameraType == "IPC"):
        signal.signal(signal.SIGINT, sigint_handler_ipc)

        objIpcCamera = esp_camera.espIpcCamera()
        res = objIpcCamera.init()
        print("init res: ", res)
        objIpcCamera.startCamera()
        objIpcCamera.stopCamera()
    elif (cameraType == "Mipi"):
        signal.signal(signal.SIGINT, sigint_handler_mipi)

        objMipiCamera = esp_camera.espMipiCamera()
        res = objMipiCamera.init()
        print("init res: ", res)
        objMipiCamera.startCamera()
        objMipiCamera.stopCamera()
