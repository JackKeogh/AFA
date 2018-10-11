/// <summary>
/// A class to control everything game related.
/// </summary>

#pragma once
#include "stdafx.h"

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

};
