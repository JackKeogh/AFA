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

	// Create Asset Handler
	m_assetLoader = AssetHandler::getInstance();
	if (!m_assetLoader)
	{
		return false;
	}
	LoadAssets();

	// Create SceneManager
	m_sceneManager = new SceneManager;
	if (m_sceneManager == nullptr)
	{
		return false;
	}
	m_sceneManager->LoadNextLevel();

	return true;
}

void Game::LoadAssets()
{
	m_assetLoader->addTexture("Top", "Assets/Tiles/Top.png", RenderSystem::Renderer());
	m_assetLoader->addTexture("Bottom", "Assets/Tiles/Bottom.png", RenderSystem::Renderer());
	m_assetLoader->addTexture("Left", "Assets/Tiles/Left.png", RenderSystem::Renderer());
	m_assetLoader->addTexture("Right", "Assets/Tiles/Right.png", RenderSystem::Renderer());
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
	SDL_Quit();
}