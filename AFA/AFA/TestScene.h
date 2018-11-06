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

		m_playerFactory = new PlayerFactory;

		m_assets = AssetHandler::Instance();
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

		if (m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives() != currentLives)
		{
			ResetLevel();
		}
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

	void Initialise() override 
	{
		m_entityManager->Clear();

		LoadLevel();

		m_playerFactory->CreateEntity(m_entityManager, "Assets/Characters/Temp.png", 60, 136, 64, 64);

		currentLives = m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives();
	};

	void ResetLevel()
	{
		for (jk::Entity * e : m_entityManager->getGroup(jk::Groups::TileGroup))
		{
			e->setActive(false);
		}

		m_entityManager->Refresh();

		currentLives--;

		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().setLives(currentLives);

		LoadLevel();
	}

	void LoadLevel() override 
	{
		m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Top.png", 180, 442, 64, 64);
		m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Top.png", 700, 492, 64, 64);

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
						m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 60 * row, 592, 60, 64);
					}
				}
				else
				{
					m_tileFactory->CreateEntity(m_entityManager, "Assets/Tiles/Bottom.png", 60 * row, 656, 60, 64);
				}
			}
		}
	};

private:
	// Asset Handler
	AssetHandler * m_assets;

	InputSystem * m_inputSystem;
	jk::EntityManager * m_entityManager;
	
	// Lives
	int currentLives;

	//Create the factories
	PlayerFactory * m_playerFactory;
	TileFactory * m_tileFactory;
};