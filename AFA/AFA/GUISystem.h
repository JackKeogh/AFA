#pragma once
#include "stdafx.h"
#include "Basics.h"

class GUISystem
{
public:
	GUISystem() 
	{
		AssetHandler * assets = AssetHandler::getInstance();

		m_holder = new Sprite(assets->getTexture("Holder"), SDL_Rect{ 0, 0, 170, 34 }, SDL_Rect{ 10, 10, 170, 34 });
		m_heatBar = new Sprite(assets->getTexture("Heat"), SDL_Rect{ 0, 0, 32, 32 }, SDL_Rect{ 11, 11, 168, 32 });
		m_livesSprite = new Sprite(assets->getTexture("Avatar"), SDL_Rect{ 0, 0, 32, 32 }, SDL_Rect{ 1154, 8, 40, 40 });
		m_livesText = new Text(assets->getFont("Arial"), SDL_Rect{ 1200, 10, 0,0 }, SDL_Color{ 0, 0, 0, 0 }, "x 3");
	};

	void Update(float org, float current)
	{
		float s = current / org;
		m_heatBar->setScale(s);
	};

	void Render()
	{
		m_holder->Render();
		m_heatBar->Render();
		m_livesSprite->Render();
		m_livesText->Render();
	}

	void setText(int value)
	{
		string text = "x " + to_string(value);
		m_livesText->setText(text);
	}

private:
	Sprite * m_holder;
	Sprite * m_heatBar;
	Sprite * m_livesSprite;
	Text * m_livesText;
};