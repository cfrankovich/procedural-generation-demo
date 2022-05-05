#include <SDL2/SDL.h>
#include "text.h"
#include "drawing.h"

void draw_grid_lines(SDL_Renderer *r, int size, int w, int h)
{
	SDL_Rect line; 
	for (int i = 1; i < h/size; i++)
	{
		line.w = 1;
		line.h = h;
		line.y = 0;
		line.x = i * size; 
		SDL_RenderDrawRect(r, &line);
		line.y = i * size;
		line.x = 0;
		line.w = w;
		line.h = 0;
		SDL_RenderDrawRect(r, &line);
	}

}

void draw_numbers(SDL_Renderer *r)
{

}

