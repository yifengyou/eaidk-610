import serial
import time

while True:
    #创建对象
    #选择串口，并设置波特率
    ser = serial.Serial('/dev/ttyUSB0', 9600)  
    if ser.is_open:
        print("port open success")
        send_data =bytes.fromhex('01 04 00 01 00 01 60 0a')
        ser.write(send_data)   # 发送命令
        time.sleep(0.5)        # 延时，否则len_return_data将返回0，此处易忽视！！！
        len_return_data = ser.inWaiting()  # 获取缓冲数据（接收数据）长度
        print('try to get the temperatur...')
        if len_return_data:
            return_data = ser.read(len_return_data)  # 读取缓冲数据
            # bytes(2进制)转换为hex(16进制)
            str_return_data = str(return_data.hex())
            temperature = int(str_return_data[-8:-4],16)/10
            print('temperature is {} ℃'.format(temperature))
    else:
        print("port open failed")

    ser.close()

    time.sleep(2)