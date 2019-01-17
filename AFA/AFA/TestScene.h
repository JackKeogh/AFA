#pragma once
#include "Scene.h"
#include <ECS.h>
#include "Components.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "TransitionSystem.h"
#include "Factory.h"
#include "SoundSystem.h"
#include "GUISystem.h"
#include "PauseMenu.h"

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

		m_musicPlayer = new SoundSystem;
		
		m_itemFactory = new ItemFactory;

		m_imageFactory = new ImageFactory;

		m_assets = AssetHandler::getInstance();

		m_gui = new GUISystem;

		m_pause = new PauseMenu;

		m_state = States::Start_Transition;
	};

	~TestScene() {};

	void Update(float delta_time) override 
	{
		// Stateless systems
		m_musicPlayer->Update();

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

			m_inputSystem->Update(m_entityManager, m_entityManager->getGroup(jk::Groups::PlayerGroup));

			MovementSystem::Move(m_entityManager->getGroup(jk::Groups::PlayerGroup), delta_time);

			CollisionSystem::TileLAR(m_entityManager->getGroup(jk::Groups::TileGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));

			CollisionSystem::TileTAB(m_entityManager->getGroup(jk::Groups::TileGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));

			CollisionSystem::Item(m_entityManager->getGroup(jk::Groups::ItemGroup), m_entityManager->getGroup(jk::Groups::PlayerGroup));

			m_entityManager->Update();
			m_entityManager->Refresh();

			CameraSystem::Update(m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<TransformComponent>().position.x);

			auto& ent = m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0);
			m_gui->Update(ent->getComponent<StatComponent>().getOrg(), ent->getComponent<StatComponent>().getHeat());

			if (m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives() != currentLives)
			{
				if (m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives() >= 0)
				{
					m_state = States::Reset_Transition;
					m_transition->setAlpha(0);
					ResetLevel();
					ResetPlayer();
					ResetSystems();

					m_gui->setText(m_entityManager->getGroup(jk::Groups::PlayerGroup).at(0)->getComponent<StatComponent>().getLives());
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

		m_gui->Render();

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
		else if (m_state == States::Pause)
		{
			m_pause->Render();
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
				if (LocalEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					m_state = States::Pause;
				}
				m_inputSystem->KeyPressed(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
				m_inputSystem->KeyReleased(LocalEvent, m_entityManager->getGroup(jk::Groups::PlayerGroup));
			}
			else if (m_state == States::Pause)
			{
				SDL_Rect mouse{ 0, 0, 2, 2 };
				SDL_GetMouseState(&mouse.x, &mouse.y);

				Button * button = m_pause->getButton(mouse);

				if (button != nullptr)
				{
					cout << "We Have Life" << endl;
				}
				else
				{
					cout << "Button is void of life" << endl;
				}
			}
		}
	};

	bool Running() override { return m_running; };

	void Initialise() override 
	{
		m_entityManager->Clear();

		LoadLevel();

		CameraSystem::setEndPoint(1800);

		m_musicPlayer->addMusic(Mix_LoadMUS("Assets/Music/Track_01.wav"));
		m_musicPlayer->addMusic(Mix_LoadMUS("Assets/Music/Track_02.wav"));

		m_playerFactory->CreateEntity(m_entityManager, "Assets/Characters/Temp.png", 60, 136, 30, 46);

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
		m_imageFactory->CreateEntity(m_entityManager, m_assets->getTexture("Background"), 0, 0, 1800, 720, jk::Layers::Background);
		m_imageFactory->CreateEntity(m_entityManager, m_assets->getTexture("Foreground"), 0, 0, 1800, 720, jk::Layers::Foreground);

		m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 180, 442, 64, 64);
		m_tileFactory->CreateEntity(m_entityManager, m_assets->getTexture("Top"), 240, 442, 64, 64);

		for (int row = 0; row < 30; row++)
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

		m_itemFactory->CreateEntity(m_entityManager, m_assets->getTexture("Item"), 500, 560, 22, 25, "Hot_Coco");
	};

private:
	// Asset Handler
	AssetHandler * m_assets;

	// Systems
	InputSystem * m_inputSystem;
	jk::EntityManager * m_entityManager;
	TransitionSystem * m_transition;
	SoundSystem * m_musicPlayer;
	GUISystem * m_gui;
	Menu * m_pause;

	// Lives
	int currentLives;

	//Create the factories
	PlayerFactory * m_playerFactory;
	TileFactory * m_tileFactory;
	ItemFactory * m_itemFactory;
	ImageFactory * m_imageFactory;
};