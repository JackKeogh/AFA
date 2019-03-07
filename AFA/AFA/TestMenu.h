#pragma once
#include "Menu.h"

class TestMenu : public Menu
{
public:
	TestMenu()
	{
		m_buttons = new vector<Button*>;
		m_buttons->push_back(new MainMenuButton);
		m_buttons->push_back(new ExitButton);
	}
};