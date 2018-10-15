/// <summary>
/// This class is to handle the inputs from the user and
/// carry out the relevant commands.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>

class InputSystem
{
public:
	InputSystem();

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
	/// Checks if the left mouse button is pressed or released.
	/// </summary>
	/// <param name="e">SDL_event</param>
	void MouseButton(SDL_Event e);

	/// <summary>
	/// Checks mouse movement and updates the player entities rotation.
	/// </summary>
	/// <param name="e">SDL_event</param>
	void MouseMove(SDL_Event e);

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