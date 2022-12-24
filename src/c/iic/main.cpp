#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <iostream>

#include "iic_common.h"

#define BMP280_ADD 0x76
#define DIG_START 0x88
#define TEMP_START 0xFA 
#define CTRL_MEAS 0xF4 
#define TEMP_ONLY_NORMAL_MODE 0xE3 // 111 000 11


int main()
{	
	FILE *fp;
    char buffer[20];
    fp=popen("tr -d '\\0' </proc/device-tree/compatible | cut -d ',' -f 3","r");
    fread(buffer,1,sizeof(buffer),fp);
    pclose(fp);

	char I2C_FILE_NAME[20];

    if (strcmp(buffer, "rk3228h\n") == 0)
	{
		strcpy(I2C_FILE_NAME, "/dev/i2c-0");
	}
	else if (strcmp(buffer, "rk3399\n") == 0)
	{
	 	strcpy(I2C_FILE_NAME, "/dev/i2c-7");
	}

	int fd; 
	fd = i2c_open(I2C_FILE_NAME);

	if (fd == -1 )
		return -1;
	if(ioctl(fd, I2C_SLAVE, BMP280_ADD) < 0)
	{
		printf("Failed to connect to the sensor\n");
		return -1;
	}

	unsigned char write_buff[1] = {TEMP_ONLY_NORMAL_MODE};
	if(i2c_write_bytes(fd, CTRL_MEAS, write_buff,1) != 0)
	{
		printf("Failed to write to fd\n");
		return -1;
	}
	while(1)
	{
		
		unsigned char dig_buff[6];
		unsigned char tmp_buff[3];

		if(i2c_read_bytes(fd, DIG_START, dig_buff, 6)<0)
		{
			printf("Failed to read from fd\n");
			sleep(3);
			continue;
		}

		if(i2c_read_bytes(fd, TEMP_START, tmp_buff, 3)<0)
		{
			printf("Failed to read from fd\n");
			sleep(3);
			continue;
		}

		int adc_T = ((tmp_buff[0]<<16)|(tmp_buff[1]<<8)|(tmp_buff[2]))>>4;
		unsigned short dig_T1 = (dig_buff[1]<<8)|(dig_buff[0]);
		short dig_T2 = (dig_buff[3]<<8)|(dig_buff[2]);
		short dig_T3 = (dig_buff[5]<<8)|(dig_buff[4]);

		unsigned int var1 = (((double)adc_T)/16384.0-((double)dig_T1)/1024.0)*((double)dig_T2);
		unsigned int var2 = ((((double)adc_T)/131072.0-((double)dig_T1)/8192.0)*(((double)adc_T)/131072.0-((double)dig_T1)/8192.0))*((double)dig_T3);

		float T = (var1+var2)/5120.0;
		printf("Temperature is : %f \n", T);
		usleep(1000*1000);
	}
}
