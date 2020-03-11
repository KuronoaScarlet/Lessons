#include "Game.h"
#include <math.h>

Game::Game() {}
Game::~Game() {}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	Window = SDL_CreateWindow("Touhou", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window == NULL)
	{
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return false;
	}
	Render = SDL_CreateRenderer(Window, -1, 0);
	if (Render == NULL)
	{
		SDL_Log("Unable to create rendering context: %s", SDL_GetError());
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	Image = IMG_Load("Flandre.png");
	player = SDL_CreateTextureFromSurface(Render, Image);
	SDL_FreeSurface(Image);

	Image = IMG_Load("Shot.png");
	shot = SDL_CreateTextureFromSurface(Render, Image);
	SDL_FreeSurface(Image);
	
	for (int i = 0; i < MAX_KEYS; ++i)
		keys[i] = KEY_IDLE;

	Player.Init(20, WINDOW_HEIGHT / 2, 90, 75, 7);
	idx_shot = 0;

	return true;
}

void Game::Release()
{
	SDL_DestroyTexture(player);

	SDL_Quit();
}

bool Game::Input()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)	return false;
	}

	SDL_PumpEvents();
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keyboard[i])
			keys[i] = (keys[i] == KEY_IDLE) ? KEY_DOWN : KEY_REPEAT;
		else
			keys[i] = (keys[i] == KEY_REPEAT || keys[i] == KEY_DOWN) ? KEY_UP : KEY_IDLE;
	}

	return true;
}

bool Game::Update()
{
	if (!Input())	return true;



	int fx = 0, fy = 0;
	if (keys[SDL_SCANCODE_ESCAPE] == KEY_DOWN)	return true;
	if (keys[SDL_SCANCODE_UP] == KEY_REPEAT)	fy = -1;
	if (keys[SDL_SCANCODE_DOWN] == KEY_REPEAT)	fy = 1;
	if (keys[SDL_SCANCODE_LEFT] == KEY_REPEAT)	fx = -1;
	if (keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT)	fx = 1;
	if (keys[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		int x, y, w, h;
		Player.GetRect(&x, &y, &w, &h);
		Shots[idx_shot].Init(x + w - 40, y + (h >> 1) - 19, 32, 32, 5);
		idx_shot++;
		Shots[idx_shot].Init(x + w - 40, y + (h >> 1) - 19, 32, 32, 5);
		idx_shot++;
		idx_shot %= MAX_SHOTS;
	}

	Scene.Move(-1, 0);
	if (Scene.GetX() <= -Scene.GetWidth())	Scene.SetX(0);

	Player.Move(fx, fy);

	for (int i = 0; i < MAX_SHOTS; ++i)
	{
		if (Shots[i].IsAlive())
		{
			Shots[i].Move(1, 0);
			if (Shots[i].GetX() > WINDOW_WIDTH)	Shots[i].ShutDown();
		}
	}

	return false;
}

void Game::Draw()
{
	SDL_Rect rc = {};

	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 100;
	Uint32 sprite = seconds % 4;

	SDL_Rect srcrect = { sprite * 58, 0, 58, 51 };

	SDL_SetRenderDrawColor(Render, 0, 0, 0, 255);
	SDL_RenderClear(Render);

	Player.GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
	SDL_RenderClear(Render);
	SDL_RenderCopy(Render, player, &srcrect, &rc);

	SDL_SetRenderDrawColor(Render, 0, 0, 192, 255);
	for (int i = 0; i < MAX_SHOTS; ++i)
	{
		if (Shots[i].IsAlive())
		{
			Shots[i].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
			SDL_RenderCopy(Render, shot, NULL, &rc);
		}
	}

	SDL_RenderPresent(Render);

	SDL_Delay(10);
}