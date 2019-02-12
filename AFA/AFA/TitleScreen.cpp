#include "SceneManager.h"

void TitleScreen::LoadLevel()
{
	SceneManager::ChangeScene(SceneManager::Scenes::Test);
}