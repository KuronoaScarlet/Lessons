#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment ( lib, "SDL_image/libx86/SDL2_image.lib" )

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window* window = SDL_CreateWindow("SDL2 Sprite Sheets", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 700, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface* image = IMG_Load("spritesheet.png");
	SDL_Texture* player = SDL_CreateTextureFromSurface(renderer, image);

	SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	SDL_RenderClear(renderer);

	while (!quit)
	{
		Uint32 ticks = SDL_GetTicks();
		Uint32 seconds = ticks / 100;
		Uint32 sprite = seconds % 4;

		SDL_Rect srcrect = { sprite * 58, 0, 58, 51 };
		SDL_Rect dstrect = { 10, 10, 58, 51 };

		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, player, &srcrect, &dstrect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(player);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}