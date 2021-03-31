#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>


gpio_s DATA;
FILE *fp;

int main(void){

	printf("Please enter pin num:\n");
	scanf("%s",&DATA.pin);
	printf("Please enter direction (in/out):\n");
        scanf("%s",&DATA.direction);
	printf("Please enter value\n");
        scanf("%s",&DATA.value);

        if (access("/tmp/export", F_OK) != 0 )
       	{
		fp = fopen("/tmp/export","wb");
		fwrite(DATA.pin,sizeof(DATA.pin[0]),sizeof(DATA.pin)/sizeof(DATA.pin[0]),fp);
		fclose(fp);
	}

	char direct[11], val[7], part[50];
        strcpy(part, "/sys/class/gpio/gpio");	
	strcpy(direct, "/direction");
	strcpy(val, "/value");
	strncat(part,DATA.pin,sizeof(DATA.pin));
	printf("%s\n", part);
	char part_save[100];
	strcpy(part_save, part);
	strncat(part,direct,sizeof(direct));
	printf("%s\n", part);
	strncat(part_save,val,sizeof(val));
	printf("%s\n", part_save);
}
