#include "SDL/include/SDL.h"
#include <iostream>

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

bool init();

void close();

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;




bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("AhegaoElCapo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		return success;
	}
}

void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}


int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event e;

	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
					break;
				}
			}

			SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 20, 200, 60));
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(2000);
		}

		close();
	}

	return 0;
}