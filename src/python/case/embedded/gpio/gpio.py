import os, sys
import getopt
import time
from enum import Enum
import signal



IN = 54
OUT = 54
SCLK = 54
RCLK = 56
DIO = 64
RESET = 0xFF

stop_flag =0
value_file = 'path'

def handler(signum, frame):
	global stop_flag
	print('Signal handler called with signal',signum)
	stop_flag =1

LED_0F = [0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98,0x8C,0xBF,0xC6,0xA1,0x86,0x8E,0xbf]
gpio_digital = [SCLK,RCLK,DIO]
fd_digital = [0,0,0]

class DIRECTION(Enum):
	INVALI_DIRECTION = 0
	INPUT = 1
	OUTPUT =2

class EDGE(Enum):
	INVALI_EDGE =0
	NONE =1
	RISING =2
	FALLING =3
	BOTH =4




def gpio_init(gpio,direction,edge,value):
	# memset(cmd,0,sizeof(cmd));
	# sprintf(cmd,"echo %d > /sys/class/gpio/export",gpio);
	# system(cmd);
	cmd = 'echo {} >/sys/class/gpio/export'.format(gpio)
	os.system(cmd)

	if (direction ==DIRECTION.INPUT):
		file = '/sys/class/gpio/gpio{}/direction'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('in')
	elif (direction ==DIRECTION.OUTPUT):
		file = '/sys/class/gpio/gpio{}/direction'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('out')

	if (edge == EDGE.NONE):
		file = '/sys/class/gpio/gpio{}/edge'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('none')

	if (edge == EDGE.RISING):
		file = '/sys/class/gpio/gpio{}/edge'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('rising')

	if (edge == EDGE.FALLING):
		file = '/sys/class/gpio/gpio{}/edge'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('falling')

	if (edge == EDGE.BOTH):
		file = '/sys/class/gpio/gpio{}/edge'.format(gpio)
		with open(file,'w') as fd_tmp:
			fd_tmp.write('both')

	if(value != None):
		global value_file
		value_file = '/sys/class/gpio/gpio{}/value'.format(gpio)


def set_voltage( fd_path,value):
	with open(fd_path,'w') as fd_file:
		fd_file.write(str(value))
	# if(value ==0):
	# 	fd.write('0')
	# else:
	# 	fd.write('1')

def get_voltage(fd):
	return fd.read()

def gpio_release(gpio):
	cmd = 'echo {} > /sys/class/gpio/unexport'.format(gpio)
	os.system(cmd)


def usage():
	print('\n---------------使用方法----------------------\n')
	print('python3 gpio.py -b(或者--button) #运行按钮模块\n')
	print('python3 gpio.py -l(或者--led) #运行LED灯模块\n')

def led_demo(gpio,direction,edge,value):
	signal.signal(signal.SIGINT, handler) 

	voltage =1
	gpio_init(gpio,direction,edge,True)

	while (stop_flag ==0):
		if voltage ==0:
			voltage =1
		else:
			voltage =0
		set_voltage(value_file,voltage)
		print('voltage',voltage)
		time.sleep(2)
	gpio_release(IN)



def button_demo(gpio,direction,edge,value):
	signal.signal(signal.SIGINT, handler) 

	button_value = 0
	button_value_last =0

	gpio_init(gpio,direction,edge,True)
	# print('value_file',value_file)
	with open(value_file,'r') as fd_int:
		while(stop_flag ==0):
			fd_int.seek(0, 0)
			button_value = int(get_voltage(fd_int))
			# print(button_value==1,'int button_value')
			conditionpara = (button_value==1 and button_value_last==0)
			if (conditionpara):
				print("button is pressed")
			button_value_last = button_value
			time.sleep(0.1)
	gpio_release(IN)


def LED_OUT(x):
	for i in [8,7,6,5,4,3,2,1]:
		if(x&0x80):
			set_voltage(fd_digital[2],1)
		else:
			set_voltage(fd_digital[2],0)
		x = (x<<1)
		set_voltage(fd_digital[0],0)
		set_voltage(fd_digital[0],1)


def LED_DISPLAY(p,v):
	led_table =LED_0F[0+v]
	LED_OUT(led_table)
	LED_OUT(p)
	set_voltage(fd_digital[1],0)
	set_voltage(fd_digital[1],1)
	time.sleep(1)
	# time.sleep(0.0001)
	

def digtron_demo():


	signal.signal(signal.SIGINT, handler) 

	for i in range(3):
		gpio_init(gpio_digital[i],DIRECTION.OUTPUT,EDGE.INVALI_EDGE,True)
		fd_digital[i] = value_file

	while (stop_flag ==0):
		LED_DISPLAY(0x08,1) 
		LED_DISPLAY(0x04,2)
		LED_DISPLAY(0x02,3)
		LED_DISPLAY(0x01,4)
	LED_OUT(RESET)
	LED_OUT(0x01)
	set_voltage(fd_digital[1],0)
	set_voltage(fd_digital[1],1)
	for j in range(3):
		# fd_digital[i].close()
		gpio_release(gpio_digital[i])

if __name__ == '__main__':	
	# led_demo(OUT,DIRECTION.OUTPUT,EDGE.INVALI_EDGE,True)
	# button_demo(IN,DIRECTION.INPUT,EDGE.BOTH,True)
	try:
		opts, args = getopt.getopt(sys.argv[1:],"bldh",["button","led",'digtron','help'])
	except getopt.GetoptError:
		usage()
	for opt, arg in opts:
		if opt in ('-h','--help'):
			usage()
		elif opt in ('-b','--button'):
			button_demo(IN,DIRECTION.INPUT,EDGE.BOTH,True)
		elif opt in ('-l','--led'):
			led_demo(OUT,DIRECTION.OUTPUT,EDGE.INVALI_EDGE,True)
		elif opt in ('-d','--digtron'):
			digtron_demo()


