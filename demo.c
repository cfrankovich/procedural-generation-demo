#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "text.h"
#include "tools.h"

#define FPS 60 
#define WIDTH 600 
#define HEIGHT 600
#define OPT_LIST "hdfHB:L:?"

#define RED 0
#define GREEN 1
#define BLUE 2

int main(int argc, char **argv)
{
	bool running; 
	running = true;
	SDL_Event event;

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	int32_t elapsed = 0;
	int frametime = 0;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Wave Function Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	/* Parse Args */ 
	bool FPS_FLAG = false;
	bool DEBUG_FLAG = false;
	int8_t background_color_rgb[3] = { 0, 0, 0 };
	int8_t grid_color_rgb[3] = { 100, 100, 100 };

	static struct option long_options[] = {
		{"background-color", optional_argument, 0, 'B'},
		{"grid-color",  optional_argument, 0, 'G'},
		{"help",  no_argument, 0, 'H'},
	};

	int opt_indx;
	int opt_char;

	while ((opt_char = getopt_long(argc, argv, OPT_LIST, long_options, &opt_indx)) != -1)
	{
		switch(opt_char)
		{
			case 'd':
				DEBUG_FLAG = !DEBUG_FLAG;
				break;

			case 'f':
				FPS_FLAG = !FPS_FLAG;
				break;

			case 'h':
			case 'H':
				printf("\nSYNOPSIS\n");
				printf("  demo [OPTION...]\n\n");
				printf("OPTIONS\n");
				printf("  Functional\n");
				printf("    -d, --debug\n");
				printf("      Output is extra verbose and will provide logs.\n\n");
				printf("    -f, --fps\n");
				printf("      Display the amount of frames per second being displayed.\n\n");
				printf("  Cosemetic\n");
				printf("    --background-color=HEXCOLOR\n");
				printf("      Makes the background color the six digit hexidecimal value given.\n\n");
				printf("    --grid-color=HEXCOLOR\n");
				printf("      Makes the grid and number color the six digit hexidecimal value given.\n\n");
				exit(0);
				break;

			case 'B':
				if (optarg == NULL)
				{
					printf("Please provide an argument for the background color!\n");
					exit(1);
				}
				for (int i = 0, k = 0; i < 6; i+=2, k++)
				{
					background_color_rgb[k] = get_rgb_from_hex(optarg[i], optarg[i+1]);
				}
				break;

			case 'G':
				if (optarg == NULL)
				{
					printf("Please provide an argument for the grid color!\n");
					exit(1);
				}
				for (int i = 0, k = 0; i < 6; i+=2, k++)
				{
					grid_color_rgb[k] = get_rgb_from_hex(optarg[i], optarg[i+1]);
				}
				break;

			case '?':
				//fprintf(stderr, "Unkown option %c\n", opt_char);
				break;
		}
	}

	TTF_Init();
	TTF_Font *font = TTF_OpenFont(LIBERATION_MONO_REGULAR, 12);
	TTF_Font *fonttwo = TTF_OpenFont(LIBERATION_MONO_REGULAR, 20);

	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = { 226, 44, 44 };
	SDL_Color blue = { 44, 44, 226 };

	char framecount[16] = "Frames: 0\0";
	Text_t frametext = init_text(framecount, font, 0, 288, white, renderer); 

	int updates, count;
	updates = count = 0;

	int w, h;
	SDL_Texture *boardimg = NULL;
	SDL_Rect boardrect;
	if (!DEBUG_FLAG) boardimg = IMG_LoadTexture(renderer, "./assets/board.png");
	else boardimg = IMG_LoadTexture(renderer, "./assets/boarddebug.png");
	boardrect.x = 0; boardrect.y = 0; 
	boardrect.w = 600; boardrect.h = 600;

	typedef struct {
		unsigned int id;
		SDL_Texture *img;
		SDL_Rect rect;
	} Node; 

	while (running)
	{
		elapsed = SDL_GetTicks();

		SDL_PollEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				printf("Exiting...\n");
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_q:
						printf("Exiting...\n");
						running = false;
						break;

				}
				break;

		}

		/* Background */
		SDL_SetRenderDrawColor(renderer, background_color_rgb[RED], background_color_rgb[GREEN], background_color_rgb[BLUE], 0xFF);
		SDL_RenderClear(renderer);

		/* Grid */

		/* Imgs */
		//SDL_RenderCopy(renderer, boardimg, NULL, &boardrect);

		/* FPS Counter */
		if (FPS_FLAG) 
		{
			updates++;
			if (elapsed >= 1000*count)
			{
				sprintf(framecount, "Frames: %d\0", updates);
				count++;
				updates = 0;
				frametext = init_text(framecount, font, 0, HEIGHT-10, white, renderer);
			}
			SDL_RenderCopy(renderer, frametext.texture, NULL, &frametext.rect);

		}

		SDL_RenderPresent(renderer);

		frametime = SDL_GetTicks() - elapsed;
		if (1000 / FPS > frametime) SDL_Delay((1000 / FPS) - frametime);
	}

	SDL_DestroyTexture(boardimg);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

