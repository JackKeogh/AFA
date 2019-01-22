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
		cout << "Failed to initialise SDL." << endl;
		return false;
	}

	// Initialise Audio
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) == -1)
	{
		cout << "Failed to open audio channel." << endl;
		return false;
	}

	// Initialise Text
	if (TTF_Init() < 0)
	{
		cout << "Failed to initialise Font" << endl;
		return false;
	}

	// Initialise bool
	m_running = true;

	// Initial RenderSystem
	if (!(RenderSystem::Init("Awnie's Frosty Adventure", 0, 0, 1260, 720)))
	{
		cout << "Failed to initialise render system." << endl;
		return false;
	}

	// Create Asset Handler
	m_assetLoader = AssetHandler::getInstance();
	if (!m_assetLoader)
	{
		cout << "Failed to get asset handler instance." << endl;
		return false;
	}
	LoadAssets();

	// Create SceneManager
	m_sceneManager = new SceneManager;
	if (m_sceneManager == nullptr)
	{
		cout << "Failed to create Scene Manager." << endl;
		return false;
	}
	m_sceneManager->LoadNextLevel();

	return true;
}

void Game::LoadAssets()
{

}

void Game::Run()
{
	int FRAMES_PER_SECOND = 60;
	int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;
	Uint32 START_FRAME = 0;
	int FRAME_TIME = 0;

	Uint32 old_time, current_time;
	float deltaTime;

	current_time = SDL_GetTicks();

	while (m_running)
	{
		old_time = current_time;
		current_time = SDL_GetTicks();

		deltaTime = (current_time - old_time) / 1000.0f;

		START_FRAME = SDL_GetTicks();

		//////////////////////////////////////////
		m_sceneManager->EventScene();
		m_sceneManager->UpdateScene(deltaTime);
		m_sceneManager->RenderScene();

		m_running = m_sceneManager->getScene()->Running();
		//////////////////////////////////////////

		FRAME_TIME = SDL_GetTicks() - START_FRAME;

		if (FRAME_DELAY > FRAME_TIME)
		{
			SDL_Delay(FRAME_DELAY - FRAME_TIME);
		}
	}
}

void Game::Clean()
{
	m_assetLoader->Clear();

	SDL_Quit();
}