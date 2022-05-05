#ifndef MY_DRAWING_HEADER
#define MY_DRAWING_HEADER

#include <SDL2/SDL.h>
#include "text.h"

/* Draw the grind lines on the x and y axis */ 
void draw_grid_lines(SDL_Renderer *r, int size, int h, int w);

/* Draw how many tiles are available in a grid spot */
void draw_numbers(SDL_Renderer *r);

#endif
