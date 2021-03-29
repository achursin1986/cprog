#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char filename[100]="";
	FILE *fp;
	char c;
	char *eol;
	char hw[]="helloworld!\n";
	/* reading user input */
	printf("Please enter file name:\n");
	fgets(filename,sizeof filename,stdin);

	/* process captured string */
	eol = strchr(filename,'\n');
	if (eol)
	{
		*eol = '\0';
	}
	else 
	{
		printf("Not valid string\n");
		exit(1);
	}	
	/* opening file and handling errors */
        fp = fopen(filename,"r");
	if (fp==NULL) 
	{
		printf("File opening failed with error:\n%s\n", strerror(errno));
		exit(1);
	}


       /* going through the file and printing contents */ 
	while(fread(&c, 1, 1, fp))
	{
		fputc(c, stdout);
	}
	fclose(fp);

	/* writing to defined file defined string */
	fp = fopen("/tmp/null","wb");
	fwrite(hw,sizeof(hw[0]),sizeof(hw)/sizeof(hw[0]),fp);
	fclose(fp);	
	

}


