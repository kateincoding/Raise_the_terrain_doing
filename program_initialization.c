#include "raise_the_terrain.h"

int program_initialization(sdl_rt *map)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	/* Create a new window 
	window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1260, 720,0); */

	map->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 300, 200, 0);

	if (map->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* Create a new Renderer map linked to the Window */
	map->renderer = SDL_CreateRenderer(map->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (map->renderer == NULL)
	{
		SDL_DestroyWindow(map->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		/* Falta destruir la ventana */
		SDL_Quit();
		return (1);
	}

	/*inicializar la estructura */
	map->width = 0
	map->height = 0;
	map->grid = 0;
	return (0);
}
