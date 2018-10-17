/// <summary>
/// This class will be used to bind a users choice of
/// keys to keycodes.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>

class KeyComponent : public jk::Component
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="R">SDL_Keycode for the right button.</param>
	/// <param name="L">SDL_Keycode for the left button.</param>
	/// <param name="J">SDL_Keycode for the jump button.</param>
	KeyComponent(SDL_Keycode R = SDLK_d, SDL_Keycode L = SDLK_a, SDL_Keycode J = SDLK_SPACE) :
		m_right(R), m_left(L), m_jump(J)
	{
	}

	/// <summary>
	/// Left
	/// 
	/// Returns the keycode for the left button.
	/// </summary>
	SDL_Keycode Left() { return m_left; };

	/// <summary>
	/// Right
	/// 
	/// Returns the keycode for the right button.
	/// </summary>
	SDL_Keycode Right() { return m_right; };

	/// <summary>
	/// Jump
	/// 
	/// Returns the keycode for the jump button.
	/// </summary>
	SDL_Keycode Jump() { return m_jump; };

private:
	SDL_Keycode m_right;
	SDL_Keycode m_left;
	SDL_Keycode m_jump;
};