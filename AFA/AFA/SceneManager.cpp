#include "SceneManager.h"

SceneManager::Scenes SceneManager::m_currentScene;
Scene* SceneManager::m_scene;

SceneManager::SceneManager()
{
	m_scene = new TitleScreen;
	m_currentScene = Scenes::MainMenu;
}

SceneManager::~SceneManager()
{
	delete m_scene;
}

void SceneManager::ChangeScene(SceneManager::Scenes N)
{
	switch (N)
	{
	case Scenes::MainMenu:
		delete m_scene;
		m_currentScene = N;
		m_scene = new TitleScreen;
		m_scene->Initialise();
		break;
	case Scenes::Test:
		delete m_scene;
		m_currentScene = N;
		m_scene = new TestScene;
		m_scene->Initialise();
		break;
	case Scenes::MemoryLeak:
		delete m_scene;
		m_currentScene = N;
		m_scene = new MemoryLeakScene;
		m_scene->Initialise();
		break;
	}
}

void SceneManager::LoadNextLevel()
{
	m_scene->Initialise();
}

void SceneManager::EventScene()
{
	m_scene->Event();
}

void SceneManager::UpdateScene(float delta_time)
{
	m_scene->Update(delta_time);
}

void SceneManager::RenderScene()
{
	if (m_scene != nullptr)
	{
		m_scene->Render();
	}
}