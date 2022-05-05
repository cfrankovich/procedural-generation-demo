#include "tools.h"
#include <stdio.h>
#include <stdlib.h>

int hex_ascii_to_denary(int n)
{
	if (n <= 57 && n >= 48) { return (n - 48); } /* 0-9 */
	else if (n <= 70 && n >= 65) { return (n - 55); } /* A-F */
	else if (n <= 102 && n >= 97) { return (n - 87); } /* a-f */
	else 
	{
		printf("Please enter a valid six digit hex number!\n");
		exit(1);
		return -1;
	}
}

int get_rgb_from_hex(int a, int b)
{
	/* super simple lol */
	a =  hex_ascii_to_denary(a);
	b =  hex_ascii_to_denary(b);
	a <<= 4;
	a += b;
	return a;
}
