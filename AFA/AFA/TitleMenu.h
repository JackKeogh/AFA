#pragma once
#include "Menu.h"

class TitleMenu : public Menu
{
public:
	TitleMenu()
	{
		m_buttons.push_back(new PlayButton);
		m_buttons.push_back(new ExitButton);
	}
};