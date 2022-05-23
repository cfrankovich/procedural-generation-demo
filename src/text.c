#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "text.h"

void init_text(Text_t *thetext, char *textstring, TTF_Font *font, int x, int y, SDL_Color color, SDL_Renderer *rendrr)
{
	thetext->string = textstring;
	thetext->surface = TTF_RenderText_Solid(font, textstring, color);

	int tw, th;
	thetext->texture = SDL_CreateTextureFromSurface(rendrr, thetext->surface);
	SDL_QueryTexture(thetext->texture, NULL, NULL, &tw, &th); 

	thetext->rect.x = x;
	thetext->rect.y = y;
	thetext->rect.w = tw;
	thetext->rect.h = th;

	thetext->color = color;
	thetext->font = font;
}

