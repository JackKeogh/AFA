#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "Factory.h"

class TestScene : public Scene
{
public:
	TestScene() 
	{
		RenderSystem::RenderColor(SDL_Color{ 0, 0, 0, 255 });

		m_running = true;
		
		m_inputSystem = new InputSystem;

		m_entityManager = new jk::EntityManager;

		m_tileFactory = new TileFactory;

		////////////////////////////////////////////
		
		auto& ent = m_entityManager->addEntity();
		ent.addComponent<TransformComponent>(Vector2f(60, 136), 50, 80, 0, 1, 5, 5);
		ent.addComponent<SpriteComponent>("Assets/Characters/Temp.png", 64, 64);
		ent.addComponent<CommandComponent>();
		ent.addComponent<KeyComponent>();
		ent.addComponent<RigidbodyComponent>(true, 5.0f);
		ent.addComponent<StatComponent>();
		ent.addGroup(jk::Groups::PlayerGroup);
		ent.addLayer(jk::Layers::Foreground);

		auto& a = m_entityManager->addEntity();
		a.addComponent<TransformComponent>(Vector2f(180, 442), 60, 50);
		a.addComponent<SpriteComponent>("Assets/Tiles/Top.png", 64, 64);
		a.addComponent<RigidbodyComponent>(false, 2.0f);
		a.addLayer(jk::Layers::Middleground);
		a.addGroup(jk::Groups::TileGroup);
	
		auto& b = m_entityManager->addEntity();
		b.addComponent<TransformComponent>(Vector2f(700, 492), 60, 50);
		b.addComponent<SpriteComponent>("Assets/Tiles/Top.png", 64, 64);
		b.addComponent<RigidbodyComponent>(false, 2.0f);
		b.addLayer(jk::Layers::Middleground);
		b.addGroup(jk::Groups::TileGroup);

		for (int row = 0; row < 21; row++)
		{
			for (int col = 0; col < 2; col++)
			{
				if (col == 0)
				{
					if (row == 0)
					{
						m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Left.png", 60 * row, 592, 60, 64);
					}
					else if (row == 20)
					{
						m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Right.png", 60 * row, 592, 60, 64);
					}
					else
					{
						m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Top.png", 60 * row, 592, 60, 64);
					}
				}
				else
				{
					m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Bottom.png", 60 * row, 656, 60, 64);
				}
			}
		}
		////////////////////////////////////////////
	};
	~TestScene() {};

	void Update(float delta_time) override 
	{
		for (jk::Entity * e : m_entityManager->getGroup(jk::Groups::PlayerGroup))
		{
			e->getComponent<StatComponent>().setDeltaTime(delta_time);
		}

		CollisionSystem::TileTAB(m_entityManager->getGroup(jk::Groups::TileGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));

		m_inputSystem->Update(m_entityManager, m_entityManager->getGroup(jk::Groups::PlayerGroup));

		MovementSystem::Move(m_entityManager->getGroup(jk::Groups::PlayerGroup), delta_time);

		CollisionSystem::TileLAR(m_entityManager->getGroup(jk::Groups::TileGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));
		
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

	//Create the factories
	TileFactory * m_tileFactory;
};