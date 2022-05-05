#ifndef MY_TOOLS_HEADER
#define MY_TOOLS_HEADER

#include <stdio.h>
#include <stdlib.h>

/* Returns the rgb value given two hex chars */
/* For example, FF will return 255 */
int get_rgb_from_hex(int a, int b);

/* A return value of -1 tells us that its invalid */
/* Returns the denary value of a hex character */
/* For example, F returns 15 */
int hex_ascii_to_denary(int c);

#endif
