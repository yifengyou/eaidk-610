# 打开DEBUG调试模式


* include\common.h

```
#ifdef DEBUG
#define _DEBUG	1
#else
#define _DEBUG	0
#endif
```

如果有定义DEBUG，则打开调试。那么，rk3399配置文件中添加DEBUG定义即可

```
/*
 * yyf: add extra cmd
 * */
    #define DEBUG
	#define CONFIG_CMD_YOU
	#define CONFIG_CMD_YIFENGYOU
	#define CONFIG_CMD_ROCKCHIP_SHOW_BMP
	#define CONFIG_CMD_LCD
    #define CONFIG_BOOTDELAY 99
    #define CONFIG_CMD_RARP
	#define CONFIG_CMD_NET
```

开发过程中，保持DEBUG开启










---
