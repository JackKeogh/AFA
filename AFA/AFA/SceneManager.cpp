#include "SceneManager.h"

SceneManager::Scenes SceneManager::m_currentScene;
Scene* SceneManager::m_scene;
vector<Scene*> SceneManager::m_scenesList;

SceneManager::SceneManager()
{
	m_scenesList.push_back(new TitleScreen);
	m_scenesList.push_back(new TestScene);
	m_scene = m_scenesList.at(Scenes::MainMenu);
	m_currentScene = Scenes::MainMenu;
}

SceneManager::~SceneManager()
{
	m_scenesList.clear();
}

void SceneManager::ChangeScene(SceneManager::Scenes N)
{
	switch (N)
	{
	case Scenes::MainMenu:
		m_scene->Clean();
		m_currentScene = N;
		m_scene = m_scenesList.at(m_currentScene);
		m_scene->Initialise();
		break;
	case Scenes::Test:
		m_scene->Clean();
		m_currentScene = N;
		m_scene = m_scenesList.at(m_currentScene);
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