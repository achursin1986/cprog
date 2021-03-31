#include "header.h"
#include <stdio.h>
#include <stdlib.h>


time_t t;
struct color_list {
  const char* color;
  struct color_list *next;
};

int main(void)
{
	//srand((unsigned) time(&t));
	struct timespec ts;
      	clock_gettime(CLOCK_MONOTONIC, &ts);
	srand((time_t)ts.tv_nsec);
	enum colors
	{	
		blue,
		green,
		red,
		violet
	};

	const char *get_color()
	{
		char result[]="";
		enum colors color =  (enum colors)(rand() % 4);
		printf("%s\n",color);
		switch (color)
		{
			case blue: 
				result = "blue";
				break;
			case green: 
				result = "green";
                                break;
			case red: 
				result = "red";
                                break;
			case violet: 
				result = "violet";
                                break;
		}
		return result;
	}

	struct color_list *rootcolor = malloc( sizeof(struct color_list) );
	struct color_list *nextcolor;

	rootcolor->color = get_color();
	rootcolor->next = malloc( sizeof(struct color_list) );
	nextcolor = rootcolor->next;
	nextcolor->color = get_color();
	nextcolor->next = malloc( sizeof(struct color_list) );
	nextcolor->next->color = get_color();
	nextcolor->next->next = 0;

	nextcolor = rootcolor;
	while (nextcolor != 0)
	{
		printf("%s\n",nextcolor->color);
		nextcolor = nextcolor->next;
	}	
	



}
