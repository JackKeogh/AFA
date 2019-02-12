#include "SceneManager.h"

void TitleScreen::LoadLevel()
{
	SceneManager::ChangeScene(SceneManager::Scenes::Test);
}
void TestScene::LoadLevel()
{
	if (m_state == States::TitleScreen)
	{
		SceneManager::ChangeScene(SceneManager::Scenes::MainMenu);
	}
}