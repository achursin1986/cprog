#include "shared.h"

char part[50];

const char* GPIOpath (char a[3])
{
	char val[7];
	strcpy(part, "/sys/class/gpio/gpio");
	strcpy(val, "/value");
	strncat(part,a,3);
	strncat(part,val,7);
	return part;
}
