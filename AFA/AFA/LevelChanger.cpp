#include "SceneManager.h"

void TitleScreen::LoadLevel()
{
	SceneManager::ChangeScene(SceneManager::Scenes::MemoryLeak);
}

void TestScene::LoadLevel()
{
	if (m_state == States::TitleScreen)
	{
		SceneManager::ChangeScene(SceneManager::Scenes::MainMenu);
	}
}

void MemoryLeakScene::LoadLevel()
{
	if (m_state == States::TitleScreen)
	{
		SceneManager::ChangeScene(SceneManager::Scenes::MainMenu);
	}
}