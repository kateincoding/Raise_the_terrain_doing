#ifndef _RAISE_THE_TERRAIN_H_
#define _RAISE_THE_TERRAIN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * SDL_Raise_the_terrain - Structure
 * @window: hold the address of the window
 * @renderer: renderer
 */
typedef struct SDL_Raise_the_terrain
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	unsigned int width;
	unsigned int height;
	unsigned int **grid;
} sdl_rt;

/* initialize program */
int program_initialization(sdl_rt *map);
/* read_map : get line and create the map size */
int read_map(sdl_rt *map, char *av);
void draw_stuff(sdl_rt map);
/* aux functions */
char **ft_strsplit(char const *s, char c);

#endif /* raise_the_terrain_H */
