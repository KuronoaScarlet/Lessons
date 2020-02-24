#include "SDL/include/SDL.h"
#include <iostream>	

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* Window = NULL;
SDL_Surface* ScreenSurface = NULL;

int main(int argc, char* args[]) 
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		Window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (Window == NULL)
		{
			std::cout << "Window error: " << SDL_GetError() << std::endl;
		}
		else
		{
			ScreenSurface = SDL_GetWindowSurface(Window);
			SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 20, 200, 61));
			SDL_UpdateWindowSurface(Window);
			SDL_Delay(2000);
		}

	}

	return 0;
}
