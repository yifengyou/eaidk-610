 #include <stdio.h>
 #include <string.h>
 #include <unistd.h> 
 #include "rs485_common.h"
 
 #define UART_DEVICE "/dev/ttyUSB0"
 
int main()
{
    int	ret = 0;
    int	fd;
    char	buf[1024] = {0};
 
    fd = open_uart(UART_DEVICE);
    if (fd == -1)
    {
        printf("open failed\n");
        return -1;
    }
 
    ret = set_uart_attr(fd, 9600, 8, 'N', 1);
    if (ret != 0)
    {
        printf("set opt failed\n");
        return -1;
    }
	char cmd[8]={0x01,0x04,0x00,0x01,0x00,0x01,0x60,0x0a};

	while (1)
	{
		memset(buf,0,sizeof(buf));
		if (write_data(fd,cmd,sizeof(cmd)) != sizeof(cmd))
		{
			printf("write fail\n");
			continue;
		}
		usleep(500*1000);
		if (read_data(fd,buf,sizeof(buf)) <0)
		{
			printf("read fail\n");
			continue;
		}
		float temp = buf[3]*16*16+buf[4];
		temp = temp/10;
		printf("temperature is %.1f ℃\n",temp) ;

		usleep(1000*1000);
		
	}
 
    close(fd);
 
    return ret;
}
