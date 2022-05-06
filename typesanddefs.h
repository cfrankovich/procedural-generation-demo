#ifndef MY_TYPES_AND_DEFINITIONS_HEADER
#define MY_TYPES_AND_DEFINITIONS_HEADER

#define WIDTH 600 
#define HEIGHT 600
#define FPS 60 
#define OPT_LIST "nhdfHDFS:B:L:?"
#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct {
	unsigned int id;
	SDL_Texture *img;
	SDL_Rect rect;
} Node; 

#endif 
