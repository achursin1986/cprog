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
	srand((unsigned) time(&t));
	enum colors
	{	
		blue,
		green,
		red,
		violet
	};

	const char *get_color()
	{
		char result[10]="";
		enum colors color =  (enum colors)(rand() % 4);
		switch (color)
		{
			case blue: return "blue";
			case green: return "green";
			case red: return "red";
			case violet: return "violet";
		}
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
