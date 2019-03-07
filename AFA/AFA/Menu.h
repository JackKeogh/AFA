#pragma once
#include "stdafx.h"
#include "Buttons.h"
#include "CollisionSystem.h"

class Menu
{
public:

	~Menu()
	{
		// Delete each object in vector array.
		for (int i = 0; i < m_buttons->size(); i++)
		{
			delete m_buttons->at(i);
		}

		// Delete array itself.
		delete m_buttons;
	}

	void Render()
	{
		for (int i = 0; i < m_buttons->size(); i++)
		{
			m_buttons->at(i)->Render();
		}
	}

	Button * getButton(SDL_Rect mouse)
	{
		mouse.x += CameraSystem::Camera().x;

		for (int i = 0; i < m_buttons->size(); i++)
		{
			m_buttons->at(i)->Reset();

			if (CollisionSystem::AABB(mouse, m_buttons->at(i)->Collider()))
			{
				return m_buttons->at(i);
			}
		}

		return nullptr;
	}

protected:
	vector<Button*>* m_buttons;
};