#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "shared.h"

int main()
{
	char pin[3]; 
	const char *GPIO;
	printf("Please enter pin num:\n");
	scanf("%s",pin);
	GPIO = GPIOpath(pin);
	//we open the file using open() and specify that it should be read only.
	int filedesc = open(GPIO,O_RDONLY);
	if(filedesc < 0)
	return 1;
	char value[1];
	//a character array to store the read content - just one character
	int sleeptime=150000;
	//a typical infinte loop notation
	while(1) 
	{
		usleep(sleeptime);
		if(read(filedesc, value, 1) < 0)
		write(2, "An error occurred in the read.\n", 31);
		//writing to file descriptor 1 is stdout, 2 is stderr
		else {
			write(1, value, 1);
			write(1, "\n", 1);
		}
	if(lseek(filedesc,0,SEEK_SET) < 0) return 1;
	}
	if(close(filedesc) < 0) return 1;
	return 0;
}
