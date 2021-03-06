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

void draw_numbers(SDL_Renderer *r, Node **nodes, int size, TTF_Font *f, SDL_Color c, Text_t *text)
{
	int i;
	int x, y;
	char idstring[4] = "XX\0";
	for (i = 0; i < WIDTH/size * HEIGHT/size; ++i)
	{
		sprintf(idstring, "%d\0", nodes[i]->id);
		x = nodes[i]->rect.x + size/2 - 12;
		y = nodes[i]->rect.y + size/2 - 12;
		init_text(text, idstring, f, x, y, c, r); 
		SDL_RenderCopy(r, text->texture, NULL, &text->rect);
		SDL_DestroyTexture(text->texture);
		SDL_FreeSurface(text->surface);
	}
}

