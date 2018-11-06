/// <summary>
/// A class to control everything game related.
/// </summary>

#pragma once
#include "stdafx.h"
#include "RenderSystem.h"
#include "SceneManager.h"

class Game
{
public:
	// Constructor
	Game();

	// Destructor
	~Game();

	/// <summary>
	/// Initialiser
	/// 
	/// A method to initialise the variables in the
	/// Game class.
	/// </summary>
	/// <returns>A bool variable.</returns>
	bool Initialiser();

	/// <summary>
	/// LoadAssets
	/// 
	/// This function is used to load in assets.
	/// </summary>
	void LoadAssets();

	/// <summary>
	/// Run
	/// 
	/// Runs the game loop.
	/// </summary>
	void Run();

	/// <summary>
	/// Clean
	/// 
	/// Unloads the variables in the Game class.
	/// </summary>
	void Clean();

private:
	bool m_running;
	AssetHandler * m_assetLoader;
	RenderSystem * m_renderer;
	SceneManager * m_sceneManager;
};
