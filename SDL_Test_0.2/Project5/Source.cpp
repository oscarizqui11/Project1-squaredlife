#include <stdlib.h>
#include <stdio.h>
#include "include/SDL.h"

#pragma comment( lib, "x86/SDL2.lib")
#pragma comment( lib, "x86/SDL2main.lib")

int main(int argc, char* argv[])
{
	
	
		
	//printf("hello");
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface *surface;
	Uint32 rmask, gmask, bmask, amask;
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_RenderClear(renderer);
	

	
	SDL_Rect r;
	r.x = 200;
	r.y = 100;
	r.w = 240;
	r.h = 240;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &r);

	SDL_RenderPresent(renderer);

	bool running = true;

	while (running) {
		SDL_Event sevent;
		while (SDL_PollEvent(&sevent))
		{
			switch (sevent.type)
			{
			case SDL_KEYDOWN:
				if (sevent.key.keysym.sym == SDLK_ESCAPE) running = false;
				break;
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	// do some other stuff here -- draw your app, etc.

	}

	SDL_Quit();
	return(0);
}
