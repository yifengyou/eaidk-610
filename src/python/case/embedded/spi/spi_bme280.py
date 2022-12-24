import sys
import spidev
import time

TEMP_ONLY_NORMAL_MODE = 0xE3
BMP280_ADD = 0x76
DIG_START = 0x88 
TEMP_START = 0xFA
CTRL_MEAS = 0xF4 

def write_addr(spi,addr,ch):
    cmd = [addr & 0x7f, ch, 11520, 0, 8]
    spi.xfer(cmd)

def read_addr_dig(spi,addr):
    cmd = [0x80 |(addr & 0x7f), 0, 0, 0, 0, 0, 0]  #cmd数组后面的0为你想要返回的数据位数,此处我们需要六个数据，所以带6个0
    readVals = spi.xfer(cmd)
    return readVals

def read_addr_tmp(spi,addr):
    cmd = [0x80 |(addr & 0x7f), 0, 0, 0] #cmd数组后面的0为你想要返回的数据位数,此处我们需要三个数据，所以带3个0
    readVals = spi.xfer(cmd)
    return readVals


def cal_temperature(adc_T,  dig_T1,  dig_T2, dig_T3):
    var1 = (adc_T/16384.0-dig_T1/1024.0)*dig_T2
    var2 = ((adc_T/131072.0-dig_T2/8192.0)*(adc_T/131072.0-dig_T2/8192.0))*dig_T3
    T = (var1+var2)/5120.0
    return T



if __name__=="__main__":

    spi = spidev.SpiDev()
    spi.open(32766,0)

    # set the speed to 4MHz
    spi.mode = 0
    spi.max_speed_hz=115200
    spi.bits_per_word=8
    spi.lsbfirst = False

    write_addr(spi,CTRL_MEAS,TEMP_ONLY_NORMAL_MODE)

    while(True):
        dig_buff =(0,0,0,0,0,0)
        tmp_buff = (0,0,0)
        dig_buff = read_addr_dig(spi,DIG_START)
        tmp_buff = read_addr_tmp(spi,TEMP_START)

        #返回数组的有效数据均从index 1开始
        adc_T = ((tmp_buff[1]<<16)|(tmp_buff[2]<<8)|(tmp_buff[3]))>>4 
        dig_T1 = (dig_buff[2]<<8)|(dig_buff[1])
        dig_T2 = (dig_buff[4]<<8)|(dig_buff[3])
        dig_T3 = (dig_buff[6]<<8)|(dig_buff[5])


        print("The temperature is :{:.4}℃".format(cal_temperature(adc_T, dig_T1, dig_T2, dig_T3)))
        time.sleep(1)

    spi.close()
    print("Done")
