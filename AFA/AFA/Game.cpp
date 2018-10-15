#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Initialiser()
{
	// Initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	// Initialise bool
	m_running = true;

	// Initial RenderSystem
	if (!(RenderSystem::Init("Awnie's Frosty Adventure", 0, 0, 1260, 720)))
	{
		return false;
	}

	// Create SceneManager
	m_sceneManager = new SceneManager;
	if (m_sceneManager == nullptr)
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

		//////////////////////////////////////////
		m_sceneManager->EventScene();
		m_sceneManager->UpdateScene();
		m_sceneManager->RenderScene();

		m_running = m_sceneManager->getScene()->Running();
		//////////////////////////////////////////

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