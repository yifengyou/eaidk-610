import cv2
import os, sys, time
sys.path.append("../../../platform/source/common")
import esp_json
from esp_json import ESP_JSON_getJsonValue
from PIL import Image
import select, numpy
import v4l2capture

class espUsbCamera(object):
	def init(self):
		self.cap = cv2.VideoCapture("/dev/video5")
		self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
		self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
		self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter.fourcc('M', 'J', 'P', 'G'))

	def setFrame(self, width, height):
		self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
		self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)

	def startCamera(self):
		while (self.cap.isOpened()):
			ret, frame = self.cap.read()
			cv2.imshow("USBCamera", frame)
			if cv2.waitKey(1) & 0xFF == ord('q'):
				break

	def stopCamera(self):
		self.cap.release()
		cv2.destroyAllWindows()

class espIpcCamera(object):
	def _init_(self):
		self.mCameraIp = ''
		self.url = ''
	
	def getUrl(self):
		self.mCameraIp = ESP_JSON_getJsonValue("ipc")
		self.url = 'rtsp://admin:admin@' + self.mCameraIp + ':554/h264/ch1/sub/av_stream'  #因为使用主码流是1080p的分辨率，OpenCV解码会卡顿，所以我们使用次码流（640*480）

	def init(self):
		self.getUrl()
		self.cap = cv2.VideoCapture(self.url)
		self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
		self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

	def startCamera(self):
		while (self.cap.isOpened()):
			ret, frame = self.cap.read()
			cv2.namedWindow("IpcCamera",0)
			cv2.resizeWindow("IpcCamera", 640, 480)
			cv2.imshow("IpcCamera", frame)
			if cv2.waitKey(1) & 0xFF == ord('q'):
				break
	
	def stopCamera(self):
		self.cap.release()
		cv2.destroyAllWindows()

class espMipiCamera(object):
	def init(self):
            self.width = 640
            self.height = 480
            camno = 2
            path = "/sys/class/video4linux"
            filenum = len([lists for lists in os.listdir(path) if os.path.isdir(os.path.join(path, lists))])
            for i in range(filenum):
                with open("/sys/class/video4linux/video"+ str(i)+"/name", 'r') as f:
                    if f.read() is "rkisp10_mainpath":
                        camno = i
                        break
            print("camno: ", camno)
            self.video = v4l2capture.Video_device("/dev/video"+str(camno), "/dev/video"+str(camno-1))
            size_x, size_y = self.video.set_format(self.width, self.height)
            print("sizex: ", size_x)
            print("sizey: ", size_y)
            self.video.create_buffers(4)
            self.video.queue_all_buffers()

	def startCamera(self):
            self.video.start()
            while True:
                select.select((self.video,), (), ())
                image_data = self.video.read_and_queue()
                im = Image.frombytes('RGB', (self.width, self.height), image_data, 'raw', 'RGB')
                arr = numpy.asarray(im)
                im = Image.fromarray(numpy.uint8(arr))
                arr = numpy.asarray(im)
                cv2.imshow("mipi camera", arr)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
	
	def stopCamera(self):
		self.video.close()
		#cv2.destroyAllWindows()
