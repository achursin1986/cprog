#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

float loadfloat;
char loadavg[4];
FILE *fp;
int main(void)
{

	while(1) 
	{
		fp=fopen("/proc/loadavg", "r");
		fread(loadavg,4,1,fp);
		loadfloat=atof(loadavg);

		/* compare this with 0.5 to illustrate our if-then-else */
		if ( loadfloat < 0.1 ) {
		printf("Green\n");
		}
		else if (loadfloat < 0.5 ) {
		printf("Yellow\n");
		}
		else if (loadfloat < 2 ) {
		printf("Red\n");
		}
		else {
		printf("Stop it\n");
		}
		fclose(fp);
		sleep(15);
	}
}
