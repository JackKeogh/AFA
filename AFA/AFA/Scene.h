/// <summary>
/// This is an abstract class for scenes to inherit from.
/// </summary>

#pragma once
#include "stdafx.h"
#include "States.h"

class Scene
{
public:
	// Destructor
	virtual ~Scene() {};

	/// <summary>
	/// Clean
	/// 
	/// Cleans up all data when the scene closes.
	/// </summary>
	virtual void Clean() = 0;

	/// <summary>
	/// Update
	/// 
	/// Updates the scene class.
	/// </summary>
	virtual void Update(float delta_time) = 0;

	/// <summary>
	/// Render
	/// 
	/// Renders the scene class.
	/// </summary>
	virtual void Render() = 0;

	/// <summary>
	/// Event
	/// 
	/// Handles the input events for the scene class.
	/// </summary>
	virtual void Event() = 0;

	/// <summary>
	/// Running
	/// 
	/// Checks if the scene is running.
	/// </summary>
	/// <returns>A bool value.</returns>
	virtual bool Running() = 0;

	/// <summary>
	/// Initialise
	/// 
	/// initialises the scene.
	/// </summary>
	virtual void Initialise() = 0;

	/// <summary>
	/// Load Level
	/// 
	/// Loads the next level.
	/// </summary>
	virtual void LoadLevel() = 0;

protected:
	bool m_running;
	States m_state;
};