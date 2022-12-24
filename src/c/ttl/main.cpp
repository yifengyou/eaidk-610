 #include <stdio.h>
 #include <string.h>
 #include <unistd.h> 
 #include "ttl_common.h"
 
 #define UART_DEVICE "/dev/ttyUSB0"
 
int main()
{
    int	ret = 0;
    int	fd;
    char buf[1024] = {0};
 
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
	char cmd[]="AT+V\r\n";
	while (1)
	{
		memset(buf,0,sizeof(buf));
		if (write_data(fd,cmd,strlen(cmd)) != strlen(cmd))
		{
			printf("write fail\n");
			continue;
		}
		usleep(100*1000);
		if (read_data(fd,buf,sizeof(buf)) <= 0)
		{
			printf("read fail\n");
			continue;
		}
		char* p = strchr(buf,'\r');
		if (p != NULL)
			*p = 0;
		printf("smoke concentration voltage is %s V\n",buf) ;

		usleep(1000*1000);
		
	}
 
    close(fd);
 
    return ret;
}
