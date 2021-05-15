#include "my_sdl2.h"

int init_instance(SDL_Instance *instance)
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

    instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 300, 200, 0);

    if (instance->window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    /* Create a new Renderer instance linked to the Window */
    instance->renderer = SDL_CreateRenderer(instance->window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (instance->renderer == NULL)
    {
        SDL_DestroyWindow(instance->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    return (0);
}

void draw_stuff(SDL_Instance instance)
{
    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}

int poll_events()
{
    SDL_Event event;
    SDL_KeyboardEvent key;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT;
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

int main()
{
    SDL_Instance instance;
    /* Only returns 0 when it succeeds */
    if (init_instance(&instance) != 0)
        return (1);
    while (1)
    {
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        if (poll_events() == 1)
            break;
        /* Draw something here */
        draw_stuff(instance);
        SDL_RenderPresent(instance.renderer);
    }
    /* Release SDL variables and others */
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    return (0);
}
