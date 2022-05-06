#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "text.h"

Text_t init_text(char *textstring, TTF_Font *font, int x, int y, SDL_Color color, SDL_Renderer *rendrr)
{
	Text_t text;
	int tw, th;
	text.string = textstring;
	text.surface = TTF_RenderText_Solid(font, textstring, color);
	text.texture = SDL_CreateTextureFromSurface(rendrr, text.surface);
	SDL_QueryTexture(text.texture, NULL, NULL, &tw, &th); 
	text.rect.x = x;
	text.rect.y = y;
	text.rect.w = tw;
	text.rect.h = th;
	text.color = color;
	text.font = font;

	return text;
}

