#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "spi_common.h"
 
void write_addr(int fd,unsigned short addr,unsigned char ch)
{
	int ret;
	unsigned char  cmd[2];
	struct spi_ioc_transfer    xfer[1];

	cmd[0] = addr & 0x7f; 
	//cmd[0] = 0x80 | cmd[0];
	cmd[1] = ch;

	memset(xfer,0,1*sizeof(struct spi_ioc_transfer));
	xfer[0].tx_buf			= (unsigned long)cmd;
	xfer[0].rx_buf		= (unsigned long)NULL;
	xfer[0].len 			= 2;
	xfer[0].delay_usecs 	= 0;
	xfer[0].bits_per_word	= 8;   
	xfer[0].speed_hz		= 115200;

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &xfer);
	if (ret == -1 )
		printf("can't transfer");
}

void read_addr(int fd,unsigned short addr,unsigned char* buf, int size)
{
	int ret;
	unsigned char  cmd[1];
	struct spi_ioc_transfer    xfer[2];

	cmd[0] = addr & 0x7f; 
	cmd[0] = 0x80 | cmd[0];
	memset(xfer,0,2*sizeof(struct spi_ioc_transfer));
	
	xfer[0].tx_buf			= (unsigned long)cmd;
	xfer[0].rx_buf			= (unsigned long)NULL;
	xfer[0].len 			= 1;
	xfer[0].delay_usecs 	= 0;
	xfer[0].bits_per_word	= 8;   
	xfer[0].speed_hz		= 115200;
	xfer[1].rx_buf			= (unsigned long)buf;
	xfer[1].tx_buf			= (unsigned long)NULL;
	xfer[1].len 			= size;
	xfer[1].delay_usecs 	= 0;
	xfer[1].bits_per_word	= 8;   
	xfer[1].speed_hz		= 115200;

	ret = ioctl(fd, SPI_IOC_MESSAGE(2), &xfer);
	if (ret == -1 )
		printf("can't transfer");
}