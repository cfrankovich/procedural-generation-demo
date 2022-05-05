#ifndef MY_TOOLS_HEADER
#define MY_TOOLS_HEADER

#include <stdio.h>
#include <stdlib.h>

/* just gets the rgb value from the two hex chars */
int get_rgb_from_hex(int a, int b);

/* Just returns the denary value of a hex character */
/* A return value of -1 tells us that its invalid */
int hex_ascii_to_denary(int c);

#endif
