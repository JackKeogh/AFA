#pragma once
#include "Scene.h"
#include "InputSystem.h"

class TestScene : public Scene
{
public:
	TestScene() 
	{
		RenderSystem::RenderColor(SDL_Color{ 0, 0, 0, 255 });

		m_running = true;
		
		m_inputSystem = new InputSystem;
	};
	~TestScene() {};

	void Update() override {};
	void Render() override
	{
		RenderSystem::Clear();

		RenderSystem::Present();
	};

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
		}
	};

	bool Running() override { return m_running; };
	void Initialise() override {};
	void LoadLevel() override {};

private:
	InputSystem * m_inputSystem;
};