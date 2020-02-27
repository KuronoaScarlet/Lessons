#include "SDL/include/SDL.h"
#include <iostream>

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;



bool init();

void close();

SDL_Window* Window = NULL;

SDL_Renderer* Back = NULL;
SDL_Renderer* Square = NULL;


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
		Window = SDL_CreateWindow("Render",100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		
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

	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{

		SDL_Rect fillRect = { 250, 250, 100, 100 };
		Square = SDL_CreateRenderer(Window, -1, 0);
		SDL_SetRenderDrawColor(Square, 255, 0, 0, 255);
		SDL_RenderFillRect(Square, &fillRect);
		SDL_RenderPresent(Square);

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
					case SDLK_RIGHT:
						fillRect.x += 10;
						break;
					case SDLK_LEFT:
						fillRect.x -= 10;
						break;
					case SDLK_UP:
						fillRect.y -= 10;
						break;
					case SDLK_DOWN:
						fillRect.y += 10;
						break;
					}
					break;
				}
			}
			SDL_RenderPresent(Square);
			SDL_RenderFillRect(Square, &fillRect);
			
		}

		close();
	}

	return 0;
}