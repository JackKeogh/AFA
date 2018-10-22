#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"
#include "MovementSystem.h"

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
		
		auto& ent = m_entityManager->addEntity();
		ent.addComponent<TransformComponent>(Vector2f(60, 0), 60, 64);
		ent.addComponent<SpriteComponent>("Assets/Characters/Temp.png", 64, 64);
		ent.addComponent<CommandComponent>();
		ent.addComponent<KeyComponent>();
		ent.addGroup(jk::Groups::PlayerGroup);
		ent.addLayer(jk::Layers::Middleground);

		for (int row = 0; row < 21; row++)
		{
			for (int col = 0; col < 2; col++)
			{
				if (col == 0)
				{
					if (row == 0)
					{
						auto& ent = m_entityManager->addEntity();
						ent.addComponent<TransformComponent>(Vector2f(60 * row, 592), 60, 64);
						ent.addComponent<SpriteComponent>("Assets/Tiles/Left.png", 64, 64);
						ent.addLayer(jk::Layers::Middleground);
					}
					else if (row == 20)
					{
						auto& ent = m_entityManager->addEntity();
						ent.addComponent<TransformComponent>(Vector2f(60 * row, 592), 60, 64);
						ent.addComponent<SpriteComponent>("Assets/Tiles/Right.png", 64, 64);
						ent.addLayer(jk::Layers::Middleground);
					}
					else
					{
						auto& ent = m_entityManager->addEntity();
						ent.addComponent<TransformComponent>(Vector2f(60 * row, 592), 60, 64);
						ent.addComponent<SpriteComponent>("Assets/Tiles/Top.png", 64, 64);
						ent.addLayer(jk::Layers::Middleground);
					}
				}
				else
				{
					auto& ent = m_entityManager->addEntity();
					ent.addComponent<TransformComponent>(Vector2f(60 * row, 656), 60, 64);
					ent.addComponent<SpriteComponent>("Assets/Tiles/Bottom.png", 64, 64);
					ent.addLayer(jk::Layers::Middleground);
				}
			}
		}
		////////////////////////////////////////////
	};
	~TestScene() {};

	void Update(float delta_time) override 
	{
		m_inputSystem->Update(m_entityManager, m_entityManager->getGroup(jk::Groups::PlayerGroup));

		MovementSystem::Move(m_entityManager->getGroup(jk::Groups::PlayerGroup), delta_time);

		m_entityManager->Update();
	};

	void Render() override
	{
		RenderSystem::Clear();
		
		for (jk::Entity * ent : m_entityManager->getLayer(jk::Layers::Background))
		{
			ent->Render();
		}

		for (jk::Entity * ent : m_entityManager->getLayer(jk::Layers::Middleground))
		{
			ent->Render();
		}

		for (jk::Entity * ent : m_entityManager->getLayer(jk::Layers::Foreground))
		{
			ent->Render();
		}

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