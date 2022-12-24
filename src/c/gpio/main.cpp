#include <getopt.h>
#include <stdlib.h>
#include "gpio_common.h"
#include "gpio_case.h"

enum SCENE_TYPE {
	CASE_LED = 0,
	CASE_BUTTON,
	CASE_DIGTRON,
	CASE_MAX,
};

struct goip_case {
	int case_;
	int (*case_fun)();
};


const struct goip_case goip_case_arr[CASE_MAX] = {
								{CASE_LED,&led_demo},
								{CASE_BUTTON,&button_demo},
								{CASE_DIGTRON,&digtron_demo},
							};

static void usage(char **argv)
{
	printf(
		"Usage: %s [Options]\n\n"
		"Options:\n"
		"-c, --case                   demo case: 0 -- led; 1 -- button; 2 -- digtron, default: 0"
		"\n",
		argv[0]);
}

int main(int argc, char **argv)
{
	int c;
	int (*goip_case_fun)();
	int demo_case = 0;

	while((c = getopt(argc, argv, "c:")) != -1)
	{
		switch (c)
		{
			case 'c':
				demo_case = atoi(optarg);
			break;
			default:
				usage(argv);
				return 0;
		}
	}

	if (demo_case < CASE_LED || demo_case >= CASE_MAX)
	{
    	demo_case = CASE_LED;
		printf ("case is not supported currently. Use LED instead!\n");
	}

	goip_case_fun = goip_case_arr[demo_case].case_fun;
	if ((*goip_case_fun)() < 0)
	{
		printf("run case error!\n");
	}
	return 0;
}

