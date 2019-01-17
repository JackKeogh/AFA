#pragma once
#include "stdafx.h"
#include "Buttons.h"

class Menu
{
public:
	void Render()
	{
		for (Button * button : m_buttons)
		{
			button->Render();
		}
	}

protected:
	vector<Button*> m_buttons;
};