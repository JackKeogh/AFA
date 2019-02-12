#pragma once
#include "stdafx.h"
#include "RenderSystem.h"
#include "Basics.h"
#include "States.h"

class Button
{
public:
	virtual void onClick(States & state) = 0;
	virtual void Render() = 0;
	virtual SDL_Rect Collider() = 0;
	virtual void Hightlight() = 0;
	virtual void Reset() = 0;

protected:
	Sprite * m_button;
	States m_state;
};

class PlayButton : public Button
{
public:
	PlayButton()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		m_button = new Sprite(assets->getTexture("PlayButton"), SDL_Rect{ 0, 0, 250, 50 }, SDL_Rect{ 505,180,250,50 });
		m_state = States::Play;
	}

	void onClick(States & state) override
	{
		state = m_state;
	}

	void Render() override
	{
		m_button->Render();
	}

	SDL_Rect Collider() override
	{
		return m_button->getRect();
	}

	void Hightlight() override
	{
		m_button->setSourceX(250);
	}

	void Reset() override
	{
		m_button->setSourceX(0);
	}
};

class MainMenuButton : public Button
{
public:
	MainMenuButton()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		m_button = new Sprite(assets->getTexture("MainMenuButton"), SDL_Rect{ 0, 0, 250, 50 }, SDL_Rect{ 505,335,250,50 });
		m_state = States::TitleScreen;
	}

	void onClick(States & state) override
	{
		state = m_state;
	}

	void Render() override
	{
		m_button->Render();
	}

	SDL_Rect Collider() override
	{
		return m_button->getRect();
	}

	void Hightlight() override
	{
		m_button->setSourceX(250);
	}

	void Reset() override
	{
		m_button->setSourceX(0);
	}
};

class ResumeButton : public Button
{
public:
	ResumeButton()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		m_button = new Sprite(assets->getTexture("ResumeButton"), SDL_Rect{ 0, 0, 250, 50 }, SDL_Rect{ 505,180,250,50 });
		m_state = States::Play;
	}

	void onClick(States & state) override
	{
		state = m_state;
	}

	void Render() override
	{
		m_button->Render();
	}

	SDL_Rect Collider() override
	{
		return m_button->getRect();
	}

	void Hightlight() override
	{
		m_button->setSourceX(250);
	}

	void Reset() override
	{
		m_button->setSourceX(0);
	}
};

class ExitButton : public Button
{
public:
	ExitButton()
	{
		AssetHandler * assets = AssetHandler::getInstance();
		m_button = new Sprite(assets->getTexture("ExitButton"), SDL_Rect{ 0, 0, 250, 50 }, SDL_Rect{ 505, 540, 250, 50 });
		m_state = States::Exit;
	}

	void onClick(States & state) override
	{
		state = m_state;
	}

	void Render() override
	{
		m_button->Render();
	}

	SDL_Rect Collider() override
	{
		return m_button->getRect();
	}

	void Hightlight() override
	{
		m_button->setSourceX(250);
	}

	void Reset() override
	{
		m_button->setSourceX(0);
	}
};