#ifndef _IIC_COMMON_H_
#define _IIC_COMMON_H_

void write_addr(int fd,unsigned short addr,unsigned char ch);
void read_addr(int fd,unsigned short addr,unsigned char* buf, int size);
#endif
