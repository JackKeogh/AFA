#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Loader.h"
#include "TitleMenu.h"

class TitleScreen : public Scene
{
public:
	
	TitleScreen() {};

	void Clean()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		assets->Clear();

		delete m_menu;
	}

	void Initialise() override
	{
		//////////////////////////////////////////////////////////
		Loader * load = new Loader;
		load->Load("Assets/Resources/TitleScene.json", "Level_01");
		delete load;
		////////////////////////////////////////////////////////// 
		
		m_menu = new TitleMenu;

		m_state = States::TitleScreen;

		m_running = true;
	}

	void Update(float delta_time) override
	{
		if (m_state == States::Play)
		{
			LoadLevel();
		}
		else if (m_state == States::Exit)
		{
			m_running = false;
		}
	}

	void Render() override
	{
		RenderSystem::Clear();

		if (m_state == States::TitleScreen)
		{
			m_menu->Render();
		}

		RenderSystem::Present();
	}

	void Event() override
	{
		SDL_Event LocalEvent;

		while (SDL_PollEvent(&LocalEvent))
		{
			if (LocalEvent.type == SDL_QUIT)
			{
				m_running = false;
				break;
			}

			if (m_state == States::TitleScreen)
			{
				SDL_Rect mouse{ 0, 0, 2, 2 };
				SDL_GetMouseState(&mouse.x, &mouse.y);

				Button * button = m_menu->getButton(mouse);

				if (button != nullptr)
				{
					button->Hightlight();

					if (LocalEvent.type == SDL_MOUSEBUTTONDOWN)
					{
						button->onClick(m_state);
					}
				}
			}
		}
	}

	bool Running() override
	{
		return m_running;
	}

	void LoadLevel() override;

private:
	Menu * m_menu;
};