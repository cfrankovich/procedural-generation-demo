#include <SDL2/SDL.h>
#include "text.h"
#include "drawing.h"
#include "typesanddefs.h"

void draw_grid_lines(SDL_Renderer *r, int size)
{
	SDL_Rect line; 

	line.w = 1;
	line.h = HEIGHT;
	line.y = 0;
	for (int i = 1; i < HEIGHT/size; i++)
	{
		line.x = i * size; 
		SDL_RenderDrawRect(r, &line);
	}

	line.x = 0;
	line.w = WIDTH;
	line.h = 1;
	for (int i = 1; i < WIDTH/size; i++)
	{
		line.y = i * size;
		SDL_RenderDrawRect(r, &line);
	}

}

void draw_numbers(SDL_Renderer *r, Node **nodes, int size, Text_t text)
{
	/* seg faults after a couple seconds in */
	/* prolly something with memory */
	/* returning from the function for now until fix */
	/* issue posted since class is about to change */
	return;
	int i;
	for (i = 0; i < WIDTH/size * HEIGHT/size; ++i)
	{
		char idstring[4] = "\0";
		sprintf(idstring, "%d\0", nodes[i]->id);
		int x, y;
		x = nodes[i]->rect.x + size/2 - 12;
		y = nodes[i]->rect.y + size/2 - 12;
		text = init_text(idstring, text.font, x, y, text.color, r); /* this line */ 
		SDL_RenderCopy(r, text.texture, NULL, &text.rect);
	}
}

