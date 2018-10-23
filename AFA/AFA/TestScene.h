#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"

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
		ent.addComponent<TransformComponent>(Vector2f(61, 0), 60, 64);
		ent.addComponent<SpriteComponent>("Assets/Characters/Temp.png", 64, 64);
		ent.addComponent<CommandComponent>();
		ent.addComponent<KeyComponent>();
		ent.addComponent<RigidbodyComponent>(true, 4.0f);
		ent.addGroup(jk::Groups::PlayerGroup);
		ent.addLayer(jk::Layers::Foreground);

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
						ent.addComponent<RigidbodyComponent>(false);
						ent.addLayer(jk::Layers::Middleground);
						ent.addGroup(jk::Groups::TileGroup);
					}
					else if (row == 20)
					{
						auto& ent = m_entityManager->addEntity();
						ent.addComponent<TransformComponent>(Vector2f(60 * row, 592), 60, 64);
						ent.addComponent<SpriteComponent>("Assets/Tiles/Right.png", 64, 64);
						ent.addComponent<RigidbodyComponent>(false);
						ent.addLayer(jk::Layers::Middleground);
						ent.addGroup(jk::Groups::TileGroup);
					}
					else
					{
						auto& ent = m_entityManager->addEntity();
						ent.addComponent<TransformComponent>(Vector2f(60 * row, 592), 60, 64);
						ent.addComponent<SpriteComponent>("Assets/Tiles/Top.png", 64, 64);
						ent.addComponent<RigidbodyComponent>(false);
						ent.addLayer(jk::Layers::Middleground);
						ent.addGroup(jk::Groups::TileGroup);
					}
				}
				else
				{
					auto& ent = m_entityManager->addEntity();
					ent.addComponent<TransformComponent>(Vector2f(60 * row, 656), 60, 64);
					ent.addComponent<SpriteComponent>("Assets/Tiles/Bottom.png", 64, 64);
					ent.addComponent<RigidbodyComponent>(false);
					ent.addLayer(jk::Layers::Middleground);
					ent.addGroup(jk::Groups::TileGroup);
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

		CollisionSystem::TileCollision(m_entityManager->getGroup(jk::Groups::TileGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));

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