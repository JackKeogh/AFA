#pragma once
#include "stdafx.h"
#include "Buttons.h"
#include "CollisionSystem.h"

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

	Button * getButton(SDL_Rect mouse)
	{
		mouse.x += CameraSystem::Camera().x;

		for (Button * button : m_buttons)
		{
			button->Reset();

			if (CollisionSystem::AABB(mouse, button->Collider()))
			{
				return button;
			}
		}

		return nullptr;
	}

protected:
	vector<Button*> m_buttons;
};