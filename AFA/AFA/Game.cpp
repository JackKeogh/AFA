#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Initialiser()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	m_running = true;

	if (!(RenderSystem::Init("Awnie's Frosty Adventure", 0, 0, 1260, 720)))
	{
		return false;
	}

	return true;
}

void Game::Run()
{
	int FRAMES_PER_SECOND = 60;
	int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;
	Uint32 START_FRAME = 0;
	int FRAME_TIME = 0;

	while (m_running)
	{
		START_FRAME = SDL_GetTicks();

		FRAME_TIME = SDL_GetTicks() - START_FRAME;

		if (FRAME_DELAY > FRAME_TIME)
		{
			SDL_Delay(FRAME_DELAY - FRAME_TIME);
		}
	}
}

void Game::Clean()
{
	SDL_Quit();
}