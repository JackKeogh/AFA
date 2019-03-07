#pragma once
#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Loader.h"
#include "Components.h"
#include "TestMenu.h"

class MemoryLeakScene : public Scene
{
public:
	MemoryLeakScene() {};

	~MemoryLeakScene()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		assets->Clear();

		delete m_menu;
	}

	void Clean() override
	{
		delete this;
	}

	void Initialise() override
	{
		//////////////////////////////////////////////////////////
		Loader * load = new Loader;
		load->Load("Assets/Resources/MemoryLeak.json", "Menu");
		delete load;
		////////////////////////////////////////////////////////// 

		m_menu = new TestMenu;

		m_state = States::Test;

		m_running = true;
	}

	void Update(float delta_time) override
	{
		if (m_state == States::TitleScreen)
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

		if (m_state == States::Test)
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

			if (m_state == States::Test)
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