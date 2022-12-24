#ifndef _GPIO_H_
#define _GPIO_H_
#include <stdio.h>

typedef enum 
{
	INVALI_DIRECTION,
	INPUT,
	OUTPUT, 
} DIRECTION;

typedef enum 
{
	INVALI_EDGE,
	NONE,
	RISING,
	FALLING,
	BOTH,
} EDGE;

int gpio_init(int gpio,DIRECTION direction,EDGE edge,char* value,int value_len);
int set_voltage(FILE * fd,int value);
int get_voltage(int fd);
void gpio_release(int gpio);
#endif
