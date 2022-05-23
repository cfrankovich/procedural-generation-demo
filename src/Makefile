CC = gcc
CFLAGS = -O2 -Wall
LDFLAGS =
NAME = demo 
SDL_CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_ttf SDL2_image)
SDL_LIBS := $(shell pkg-config --libs sdl2 SDL2_ttf SDL2_image)
override CFLAGS += $(SDL_CFLAGS)
override LIBS += $(SDL_LIBS)

all: create 
	@echo "Done!"

create: demo.o text.o tools.o drawing.o
	$(CC) $(LDFLAGS) -o $(NAME) $^ $(LIBS)

demo.o: demo.c 
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

text.o: text.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

tools.o: tools.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

drawing.o: drawing.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

clean:
	rm -f $(NAME) *.o
	@echo "Cleaned!"

