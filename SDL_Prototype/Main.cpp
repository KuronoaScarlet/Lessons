#include "SDL/include/SDL.h"
#include <iostream>

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )


// Screen dimension constants
const int SCREEN_WIDTH = 742;
const int SCREEN_HEIGHT = 800;

//Starts up SDL and creates Window
bool init();

//Loads media
bool loadMedia();

//Frees media  and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gImage = NULL;
SDL_Surface* gImage2 = NULL;


bool init()
{
	//Initiation flag:
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		return success;
	}
}

bool loadMedia()
{
	//Loading success flag:
	bool success = true;

	//Load Splash image:
	gImage = SDL_LoadBMP("Ahegao.bmp");
	if (gImage == NULL)
	{
		std::cout << "Unable to load the image! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	gImage2 = SDL_LoadBMP("Papaoso.bmp");
	if (gImage2 == NULL)
	{
		std::cout << "Unable to load the image! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}

void close()
{
	//Dealocate surface
	SDL_FreeSurface(gImage);
	gImage = NULL;
	SDL_FreeSurface(gImage2);
	gImage2 = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create Window
	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		//Load media
		if (!loadMedia()) {
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gImage, NULL, gScreenSurface, NULL);

			//Update Surface
			SDL_UpdateWindowSurface(gWindow);

			//Wait two seconds
			SDL_Delay(2000);

			SDL_BlitSurface(gImage2, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(3000);
		}

		//Free resources and close SDL
		close();
	}

	return 0;
}