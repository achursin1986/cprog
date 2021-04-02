#include "header.h"
#include <stdio.h>
#include <stdlib.h>


time_t t;
int i=0;
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
		enum colors color =  (enum colors)(rand() % 4);
		switch (color)
		{
			case blue: return "blue";
			case green: return "green";
			case red: return "red";
			case violet: return "violet";
		}
	}

	struct color_list *color=malloc(sizeof(struct color_list));	
	struct color_list *root = color;
	struct color_list *tmp;



	while (color != 0)
	{
		if ( i < 5 ) {
		color->color = get_color();
		printf("%s\n",color->color);
		color->next = malloc(sizeof(struct color_list));
		color = color->next;
		} 
		else {
			color->color = get_color();
			color->next = 0;
			break;
		}
		i++;

	}

	/* cleanup */
	while (root != 0)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}	


}
