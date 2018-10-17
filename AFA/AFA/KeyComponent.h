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

private:
	SDL_Keycode m_right;
	SDL_Keycode m_left;
	SDL_Keycode m_jump;
};