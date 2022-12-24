#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <string.h>
#include "spi_common.h"

#define BMP280_ADD 0x76 
#define DIG_START 0x88 
#define TEMP_START 0xFA 
#define CTRL_MEAS 0xF4 
#define TEMP_ONLY_NORMAL_MODE 0xE3 // 111 000 11


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static const char *device = "/dev/spidev32766.0";

static void pabort(const char *s)
{
	perror(s);
	abort();
}

static float cal_temperature(uint32_t adc_T, unsigned short dig_T1, short dig_T2, short dig_T3){ 
        uint32_t var1, var2; 
        float T; 
        var1 = (((double)adc_T)/16384.0-((double)dig_T1)/1024.0)*((double)dig_T2); 
        var2 = ((((double)adc_T)/131072.0-((double)dig_T1)/8192.0)*(((double)adc_T)/131072.0-((double)dig_T1)/8192.0))*((double)dig_T2); 
        T = (var1+var2)/5120.0; 
        return T; 
}

static void transfer(int fd)
{
	int ret;
	char dig_buff[6];
	char tmp_buff[3];

	read_addr(fd,DIG_START,reinterpret_cast<unsigned char*>(dig_buff),6);
	read_addr(fd,TEMP_START,reinterpret_cast<unsigned char*>(tmp_buff),3);

	int adc_T = ((tmp_buff[0]<<16)|(tmp_buff[1]<<8)|(tmp_buff[2]))>>4; 
	unsigned short dig_T1 = (dig_buff[1]<<8)|(dig_buff[0]); 
	short dig_T2 = (dig_buff[3]<<8)|(dig_buff[2]); 
	short dig_T3 = (dig_buff[5]<<8)|(dig_buff[4]); 

	printf("Temperature is : %f \n", cal_temperature(adc_T, dig_T1, dig_T2, dig_T3)); 

}

int main(int argc, char *argv[])
{
	int ret = 0;
	int fd;
	uint8_t mode;
	uint8_t bits = 8;
	uint32_t speed = 115200;
	
	fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("can't open device");
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("can't set spi mode");
	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("can't get spi mode");
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word");
	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word");
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz");
	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz");
	printf("spi mode: %d\n", mode);
	printf("bits per word: %d\n", bits);
	printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
	write_addr(fd,CTRL_MEAS,TEMP_ONLY_NORMAL_MODE);
	while(1)
	{
		transfer(fd);
		sleep(1);
	}
	close(fd);
	return 0;
}
