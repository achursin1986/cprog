#include <stdio.h>
int main(void)
{
for ( int x = 0; x < 128; x++ ) {
printf( "%d = %c\n", x, (char)x );
}
return 0;
}
