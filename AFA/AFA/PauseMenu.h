#pragma once
#include "Menu.h"

class PauseMenu : public Menu
{
public:
	PauseMenu()
	{
		m_buttons.push_back(new ResumeButton);
		m_buttons.push_back(new ExitButton);
	}
};