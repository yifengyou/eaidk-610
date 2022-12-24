#ifndef _RS485_COMMON_H_
#define _RS485_COMMON_H_

int open_uart(const char* device_name);
int set_uart_attr(int fd, int nSpeed, int nBits, char nEvent, int nStop);
int read_data(int fd,char* buf,int size);
int write_data(int fd,char* buf,int size);
#endif
