/// <summary>
/// This class will be used to manage scenes
/// </summary>

#pragma once
#include "stdafx.h"
#include "RenderSystem.h"
#include "Scene.h"
#include "TestScene.h"
#include "TitleScreen.h"

class SceneManager
{
public:
	// An enum that lists all scenes in the game.
	enum Scenes
	{
		MainMenu,
		Test
	};

	// Constructors
	SceneManager();

	// Destructors
	~SceneManager();

	/// <summary>
	/// Change Scene
	/// 
	/// A static method to allow the changing of scenes.
	/// </summary>
	/// <param name="N">The Scene to change too.</param>
	static void ChangeScene(Scenes N);

	/// <summary>
	/// Next Level
	/// 
	/// Changes the scene to the next scene in the vector.
	/// </summary>
	void LoadNextLevel();

	Scenes getCurrentState()
	{
		return Scenes::Test;
	}

	/// <summary>
	/// Event Scene
	/// 
	/// This will be used to handle the input of the current scene.
	/// </summary>
	void EventScene();

	/// <summary>
	/// Update Scene
	/// 
	/// This will be used to update the current scene.
	/// </summary>
	void UpdateScene(float delta_time);

	/// <summary>
	/// Render Scene
	/// 
	/// This will be used to render the current scene.
	/// </summary>
	void RenderScene();

	/// <summary>
	/// get Scene
	/// 
	/// returns a pointer to the current scene.
	/// </summary>
	/// <returns>A pointer to the current scene.</returns>
	Scene* getScene()
	{
		return m_scene;
	}

private:
	static Scenes m_currentScene;
	static Scene* m_scene;
	static vector<Scene*> m_scenesList;
};