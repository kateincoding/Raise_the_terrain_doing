#include "raise_the_terrain.h"

void draw_stuff(sdl_rt map)
{
	SDL_SetRenderDrawColor(map.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(map.renderer, 10, 10, 100, 100);
}

int poll_events()
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				/* If 'ESCAPE' is pressed */
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	sdl_rt map;
	/* Restriction before start */
	if (argc != 2)
	{
		dprintf(2, "Incorrect number of file, you can only give one");
		exit(EXIT_FAILURE);
	}

	/* Program_Initialization: Succes 0 */
	if (program_initialization(&map) != 0)
		return (1);
	/* Read_map */

	/* Program_Renderize */
	while (1)
	{
		SDL_SetRenderDrawColor(map.renderer, 0, 0, 0, 0);
		SDL_RenderClear(map.renderer);
		if (poll_events() == 1)
			break;
		/* Draw something here */
		draw_stuff(map);
		SDL_RenderPresent(map.renderer);
	}
	/* Program_Release : SDL variables and others */
	SDL_DestroyRenderer(map.renderer);
	SDL_DestroyWindow(map.window);
	SDL_Quit();
	return (0);
}
