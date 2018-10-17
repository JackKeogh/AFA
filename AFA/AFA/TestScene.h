#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"

class TestScene : public Scene
{
public:
	TestScene() 
	{
		RenderSystem::RenderColor(SDL_Color{ 0, 0, 0, 255 });

		m_running = true;
		
		m_inputSystem = new InputSystem;

		m_entityManager = new jk::EntityManager;

		////////////////////////////////////////////
		auto& Player = m_entityManager->addEntity();
		Player.addComponent<TransformComponent>();
		Player.addComponent<CommandComponent>();
		Player.addComponent<KeyComponent>();
		Player.addGroup(jk::Groups::PlayerGroup);
		Player.addLayer(jk::Layers::Middleground);
		////////////////////////////////////////////
	};
	~TestScene() {};

	void Update() override 
	{
		m_inputSystem->Update(m_entityManager, m_entityManager->getGroup(jk::Groups::PlayerGroup));
	};

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

			m_inputSystem->KeyPressed(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
			m_inputSystem->KeyReleased(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
		}
	};

	bool Running() override { return m_running; };
	void Initialise() override {};
	void LoadLevel() override {};

private:
	InputSystem * m_inputSystem;
	jk::EntityManager * m_entityManager;
};