#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "iic_common.h"

int i2c_open(char* dev)
{
	int fd = open(dev, O_RDWR);
	if(fd < 0){
		perror("Unable to open i2c controlfile");
		return -1;
	}
	return fd;
}

int i2c_write_bytes(int fd, unsigned char addr,unsigned char* data, unsigned short len)
{    
    unsigned char* write_data =(reinterpret_cast<unsigned char*>(malloc(len + 1)));
	if(write_data == NULL)
    {
        return -1;
    }

    write_data[0] = addr;
    memcpy(&write_data[1], data, len);
    
    
    if (write(fd, write_data, len + 1) != len+1)
    {
    	free(write_data);
		return -1;
	}

    free(write_data);
	return 0;
}


int i2c_read_bytes(int fd, unsigned char addr, unsigned char* buf, unsigned short len)
{
	char writeBuff[1] = {addr};
	if(write(fd, writeBuff, 1)!=1)
	{
		printf("Failed to reset the read address\n");
		return 1;
	}
    if (read(fd, buf, len)<0)
	{
		printf("Read data fail\n");
		return -1;
	}
	return 0;
    //printf("buf[0] = 0x%x\n", buf[0]);
    
    //printf("Read data success\n");
}