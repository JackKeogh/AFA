#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "TransitionSystem.h"
#include "Factory.h"

class TestScene : public Scene
{
public:
	TestScene() 
	{
		RenderSystem::RenderColor(SDL_Color{ 0, 0, 0, 255 });

		m_running = true;
		
		m_inputSystem = new InputSystem;

		m_transition = new TransitionSystem;

		m_entityManager = new jk::EntityManager;

		m_tileFactory = new TileFactory;

		m_playerFactory = new PlayerFactory;

		m_itemFactory = new ItemFactory;

		m_assets = AssetHandler::getInstance();

		m_state = States::Start_Transition;
	};
	~TestScene() {};

	void Update(float delta_time) override 
	{
		if (m_state == States::Start_Transition)
		{
			if (m_transition->Transition())
			{
				m_transition->Reset();
				m_state = States::Play;
			}
		}
		else if (m_state == States::Play)
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

			CameraSystem::Update(m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().position.x);

			if (m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives() != currentLives)
			{
				if (m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives() >= 0)
				{
					m_state = States::Reset_Transition;
					m_transition->setAlpha(0);
					ResetLevel();
					ResetPlayer();
					ResetSystems();
				}
				else
				{
					m_running = false;
				}
			}
		}
		else if (m_state == States::Reset_Transition)
		{
			if (m_transition->Transition())
			{
				m_transition->Reset();
				m_state = States::Play_Transition;
			}
		}
		else if (m_state == States::Play_Transition)
		{
			if (m_transition->Transition())
			{
				m_transition->Reset();
				m_state = States::Play;
			}
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

		if (m_state == States::Start_Transition)
		{
			m_transition->FadeIn();
		}
		else if (m_state == States::Reset_Transition)
		{
			m_transition->FadeOut();
		}
		else if (m_state == States::Play_Transition)
		{
			m_transition->FadeIn();
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

			if (m_state == States::Play)
			{
				m_inputSystem->KeyPressed(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
				m_inputSystem->KeyReleased(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
			}
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

		LoadLevel();
	}

	void ResetPlayer()
	{
		currentLives--;

		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().position.x = 60;
		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().position.y = 136;
		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().velocity = jk::Vector2f(0, 0);
		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().acceleration = jk::Vector2f(0, 0);
		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().setLives(currentLives);
		m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().setHeat(30.0f);
	}

	void ResetSystems()
	{
		m_inputSystem->Reset();
	}

	void LoadLevel() override 
	{
		m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 180, 442, 64, 64);
		m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 700, 492, 64, 64);

		for (int row = 0; row < 30; row++)
		{
			for (int col = 0; col < 2; col++)
			{
				if (col == 0)
				{
					if (row == 0)
					{
						m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Left"), 60 * row, 592, 60, 64);
					}
					else if (row == 29)
					{
						m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Right"), 60 * row, 592, 60, 64);
					}
					else
					{
						m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 60 * row, 592, 60, 64);
					}
				}
				else
				{
					m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Bottom"), 60 * row, 656, 60, 64);
				}
			}
		}

		m_itemFactory->CreateEntity(m_entityManager, "Assets/Items/Item.png", 500, 560, 22, 25);
	};

private:
	// Asset Handler
	AssetHandler * m_assets;

	// Systems
	InputSystem * m_inputSystem;
	jk::EntityManager * m_entityManager;
	TransitionSystem * m_transition;
	
	// Lives
	int currentLives;

	//Create the factories
	PlayerFactory * m_playerFactory;
	TileFactory * m_tileFactory;
	ItemFactory * m_itemFactory;
};