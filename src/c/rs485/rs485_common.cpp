#include <termios.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "rs485_common.h"
int open_uart(const char* device_name)
{
    int fd;
 
    fd = open(device_name, O_RDWR | O_NOCTTY | O_NDELAY);
    if (-1 == fd)
    {
        perror("Can't Open Serial Port");
        return (-1);
    }
 
    /*恢复串口为阻塞状态*/
    if (fcntl(fd, F_SETFL, 0) < 0)
    {
        printf("fcntl failed!\n");
    }
    else
    {
        printf("fcntl=%d\n", fcntl(fd, F_SETFL, 0));
    }
 
    /*测试是否为终端设备*/
    if (isatty(STDIN_FILENO) == 0)
    {
        printf("standard input is not a terminal device\n");
    }
    else
    {
        printf("isatty success!\n");
    }
 
    printf("fd-open=%d\n", fd);
    return fd;
}

int set_uart_attr(int fd, int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio, oldtio;
    /*保存测试现有串口参数设置，在这里如果串口号等出错，会有相关的出错信息*/
    if (tcgetattr(fd, &oldtio) != 0)
    {
        perror("SetupSerial 1");
        return -1;
    }
    bzero(&newtio, sizeof(newtio));
 
    /*步骤一，设置字符大小*/
    newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;
 
    /*设置停止位*/
    switch (nBits)
    {
        case 7:
            newtio.c_cflag |= CS7;
            break;
        case 8:
            newtio.c_cflag |= CS8;
            break;
    }
 
    /*设置奇偶校验位*/
    switch (nEvent)
    {
        case 'O':    //奇数
            newtio.c_cflag |= PARENB;
            newtio.c_cflag |= PARODD;
            newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'E':    //偶数
            newtio.c_iflag |= (INPCK | ISTRIP);
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;
        case 'N':    //无奇偶校验位
            newtio.c_cflag &= ~PARENB;
            break;
    }
 
    /*设置波特率*/
    switch (nSpeed)
    {
        case 2400:
            cfsetispeed(&newtio, B2400);
            cfsetospeed(&newtio, B2400);
            break;
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        case 460800:
            cfsetispeed(&newtio, B460800);
            cfsetospeed(&newtio, B460800);
            break;
        default:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
    }
 
    /*设置停止位*/
    if (nStop == 1)
    {
        newtio.c_cflag &= ~CSTOPB;
    }
    else if (nStop == 2)
    {
        newtio.c_cflag |= CSTOPB;
    }
 
    /*设置等待时间和最小接收字符*/
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN]  = 0;
 
    /*处理未接收字符*/
    tcflush(fd, TCIFLUSH);
 
    /*激活新配置*/
    if ((tcsetattr(fd, TCSANOW, &newtio)) != 0)
    {
        perror("com set error");
        return -1;
    }
 
    printf("set done!\n");
    return 0;
}

int read_data(int fd,char* buf,int size)
{
	return (read(fd, buf, size));
}
 
int write_data(int fd,char* buf,int size)
{
	return (write(fd, buf, size));
}