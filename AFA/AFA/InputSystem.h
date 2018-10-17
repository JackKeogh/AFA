/// <summary>
/// This class is to handle the inputs from the user and
/// carry out the relevant commands.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>
#include "Components.h"

class InputSystem
{
public:
	// Constructor
	InputSystem();

	// Destructor
	~InputSystem();

	/// <summary>
	/// Checks key down event and if the key pressed corresponds
	/// to a keycode belonging to a player entity.
	/// </summary>
	/// <param name="e">SDL_event</param>
	/// <param name="entity">vector of unique ptr of Entity to loop through entities until
	/// player is found.</param>
	void KeyPressed(SDL_Event e, vector<jk::Entity*> &entity);

	/// <summary>
	/// Checks key up event and if the key up corresponds
	/// to a keycode belonging to a player entity.
	/// </summary>
	/// <param name="e">SDL_event</param>
	/// <param name="entity">vector of unique ptr of Entity to loop through entities until
	/// player is found.</param>
	void KeyReleased(SDL_Event e, vector<jk::Entity*> &entity);

	/// <summary>
	/// Updates the player based on current keys pressed and released.
	/// </summary>
	/// <param name="entity">vector of unique ptr of Entity to loop through entities until
	/// player is found.</param>
	void Update(jk::EntityManager * Manager, vector<jk::Entity*> &entity);

private:
	bool m_jump;
	bool m_left;
	bool m_right;
};