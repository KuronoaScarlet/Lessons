#include "SDL/include/SDL.h"
#include <iostream>

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

bool init();

void close();

SDL_Window* Window = NULL;
SDL_Renderer* gRenderer = NULL;


bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		Window = SDL_CreateWindow("Render", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		return success;
	}
}

void close()
{
	SDL_DestroyWindow(Window);
	Window = NULL;

	SDL_Quit();
}


int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event e;

	int x = 200;
	int y = 200;

	SDL_Rect fillRect = { x, y, 100, 100 };

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
					switch (e.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						quit = true;
						break;
					case SDLK_UP:
						fillRect.y--;
						break;
					case SDLK_DOWN:
						fillRect.y++;
						break;
					case SDLK_RIGHT:
						fillRect.x++;
						break;
					case SDLK_LEFT:
						fillRect.x--;
						break;
					}
				

				}
			}
			gRenderer = SDL_CreateRenderer(Window, -1, 0);

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 50, 150, 255, 255);
			SDL_RenderClear(gRenderer);

			//Render red filled quad
			SDL_Rect fillRect = { x, y, 100, 100 };
			SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
			SDL_RenderFillRect(gRenderer, &fillRect);

			//Update screen
			SDL_RenderPresent(gRenderer);
		}

		close();
	}
	return 0;
}

