#include <unistd.h>
#include <poll.h>
#include<fcntl.h>
#include <signal.h>
#include "gpio_common.h"
#include "gpio_case.h"
#define IN 54
#define OUT 54
#define SCLK 54
#define RCLK 56
#define DIO 64
#define RESET 0xFF

bool init_status = false;

unsigned char LED_0F[] = 
{// 0   1    2    3    4    5    6     7   8     9   A    b    C    d    E    F    -
  0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98,0x8C,0xBF,0xC6,0xA1,0x86,0x8E,0xbf
};

int fd_int;
FILE * fd_file;
int stop_flag = 0;

int goip[3] = {SCLK,RCLK,DIO};
FILE * fd[3] = {NULL,NULL,NULL};

static void stop_demo (int param)
{
  stop_flag = 1;
}
static void LED_OUT(unsigned char X)
{
	int i;
	for(i=8;i>=1;i--)
	{
		if (X&0x80)
		{	
			set_voltage(fd[2],1);
		}
		else
		{
			set_voltage(fd[2],0);
		}
		X<<=1;
		set_voltage(fd[0],0);
		set_voltage(fd[0],1);
	}
}
static void LED_DISPLAY (unsigned char p,int v)
{
	unsigned char *led_table; 
	unsigned char i;

	led_table = LED_0F + v;
	i = *led_table;

	LED_OUT(i); 
	LED_OUT(p);

	set_voltage(fd[1],0);
	set_voltage(fd[1],1);
	usleep(3*1000);
}

int led_demo()
{
	int voltage = 0;
	char cmd[1024];
	char value_file[64] = {0};
	
	signal (SIGINT, stop_demo);

    if (!init_status)
	{
		if ( gpio_init(OUT,OUTPUT,INVALI_EDGE,value_file,sizeof(value_file))<0 )
		{
			return -1;
		}
		init_status = true;
	}
	fd_file = fopen(value_file,"w");
	if (fd_file == NULL)
	{
		printf("open %s fail\n",value_file);
		return -1;
	}

	while(stop_flag ==0)
	{
		if (voltage == 1)
		{
			voltage = 0;
		}
		else
		{
			voltage = 1;
		}
		set_voltage(fd_file,voltage);
		sleep(3);
	}
	fclose(fd_file);
	gpio_release(IN);
	init_status = false;
	return 0;
}


int button_demo()
{
	char cmd[1024];
	char value_file[64] = {0};
	int button_value_last = 0;
	int button_value = 0;

	signal (SIGINT, stop_demo);
	if (!init_status)
	{
		if (gpio_init(IN,INPUT,BOTH,value_file,sizeof(value_file)) < 0)
		{
			return -1;
		}
	}
	fd_int=open(value_file,O_RDONLY);
	if (fd_int <0)
	{
		printf("open %s fail\n",value_file);
		return -1;
	}
	
    struct pollfd fds[1];
    fds[0].fd=fd_int;
    fds[0].events=POLLPRI;
    while((stop_flag ==0))
    {
        if(poll(fds,1,0)==-1)
        {
            perror("poll failed!\n");
            return -1;
        }
        if(fds[0].revents&POLLPRI)
        {
            if(lseek(fd_int,0,SEEK_SET)==-1)
            {
                perror("lseek failed!\n");
                return 0;
            }
			button_value = get_voltage(fd_int);
			//printf("button_value=%d\n",button_value);
			if (button_value_last ==0 &&  button_value == 1)
			{
				printf("button is pressed\n");
			}
			button_value_last = button_value;
			usleep(1000*100);
        }
    }
	  
	close(fd_int);
	gpio_release(IN);
	init_status = false;
	return 0;
}

int digtron_demo()
{
	int i = 0;
	char cmd[1024];
	
	signal (SIGINT, stop_demo);
	
	for(i = 0; i < 3; i++)
	{
		char value_file[64] = {0};
		if (gpio_init(goip[i],OUTPUT,INVALI_EDGE,value_file,sizeof(value_file)) < 0)
		{
			return -1;
		}
		fd[i] = fopen(value_file,"w");
	}
	
	while(stop_flag ==0)
	{
		LED_DISPLAY(0x08,1);
		LED_DISPLAY(0x04,2);
		LED_DISPLAY(0x02,3);
		LED_DISPLAY(0x01,4);
	}
	  
	LED_OUT(RESET); 
	LED_OUT(0x01);
	set_voltage(fd[1],0);
	set_voltage(fd[1],1);;

	for (i=0;i<3;i++)
	{
		fclose(fd[i]);
		gpio_release(goip[i]);
	}

	return 0;
}

