#ifndef _IIC_COMMON_H_
#define _IIC_COMMON_H_

int i2c_open(char* dev);
int i2c_write_bytes(int fd, unsigned char addr,unsigned char* data, unsigned short len);
int i2c_read_bytes(int fd, unsigned char addr, unsigned char* buf, unsigned short len);
#endif
