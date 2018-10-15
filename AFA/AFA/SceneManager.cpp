#include "SceneManager.h"
#include "RenderSystem.h"
#include "Scene.h"
#include "TestScene.h"

SceneManager::Scenes SceneManager::m_currentScene;
Scene* SceneManager::m_scene;
vector<Scene*> SceneManager::m_scenesList;

SceneManager::SceneManager()
{
	m_scenesList.push_back(new TestScene);
	m_scene = m_scenesList.at(Scenes::Test);
	m_currentScene = Scenes::Test;
}

SceneManager::~SceneManager()
{
	m_scenesList.clear();
}

void SceneManager::ChangeScene(SceneManager::Scenes N)
{
	switch (N)
	{
	case Scenes::Test:
		m_currentScene = N;
		m_scene = m_scenesList.at(m_currentScene);
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

void SceneManager::UpdateScene()
{
	m_scene->Update();
}

void SceneManager::RenderScene()
{
	if (m_scene != nullptr)
	{
		m_scene->Render();
	}
}