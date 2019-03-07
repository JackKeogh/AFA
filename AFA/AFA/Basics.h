#pragma once
#include "stdafx.h"
#include "RenderSystem.h"
#include "CameraSystem.h"

class Sprite
{
private:
	SDL_Texture * m_texture;
	SDL_Rect * m_source;
	SDL_Rect * m_destination;
	float * m_rotation;
	float * m_offset;
	float * m_maxWidth;
	float * m_scale;

public:
	Sprite() {};

	Sprite(SDL_Texture * t, SDL_Rect s, SDL_Rect d)
	{
		m_texture = t;
		m_source = new SDL_Rect{ s };
		m_destination = new SDL_Rect{ d };
		m_offset = new float{ static_cast<float>(d.x) };
		m_maxWidth = new float{ static_cast<float>(d.w) };
		m_scale = new float{ 1.f };
		m_rotation = new float{ 0 };
	};

	~Sprite()
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		delete m_source;
		delete m_destination;
		delete m_rotation;
		delete m_offset;
		delete m_maxWidth;
		delete m_scale;
	}

	void Render()
	{
		SDL_Rect camera = CameraSystem::Camera();

		m_destination->x = camera.x + *m_offset;

		RenderSystem::Draw(m_texture, *m_source, *m_destination, *m_rotation);
	}

	void setScale(float value)
	{
		m_scale = &value;
		float w = (*m_maxWidth) * (*m_scale);
		m_destination->w = w;
	};

	void setSourceX(int x)
	{
		m_source->x = x;
	}

	void setSourceY(int y)
	{
		m_source->y = y;
	}

	SDL_Rect getRect()
	{
		return *m_destination;
	}
};

class Text
{
public:
	Text() {};

	Text(TTF_Font * font, SDL_Rect destination, SDL_Color colour, string text)
	{
		m_text = text;
		m_destination = destination;
		m_colour = colour;
		m_offset = destination.x;
		m_font = font;

		SDL_Surface * surface = TTF_RenderText_Solid(m_font, m_text.c_str(), m_colour);
		m_texture = SDL_CreateTextureFromSurface(RenderSystem::Renderer(), surface);

		m_destination.w = surface->w;
		m_destination.h = surface->h;

		SDL_FreeSurface(surface);
	}

	~Text()
	{
		SDL_DestroyTexture(m_texture);

		if (m_font != NULL)
		{
			TTF_CloseFont(m_font);
		}

		m_texture = NULL;
		m_font = NULL;
	}

	void setText(string value)
	{
		m_text = value;

		SDL_DestroyTexture(m_texture);

		SDL_Surface * surface = TTF_RenderText_Solid(m_font, m_text.c_str(), m_colour);
		m_texture = SDL_CreateTextureFromSurface(RenderSystem::Renderer(), surface);

		m_destination.w = surface->w;
		m_destination.h = surface->h;

		SDL_FreeSurface(surface);
	}

	void Render()
	{
		SDL_Rect camera = CameraSystem::Camera();

		m_destination.x = camera.x + m_offset;

		RenderSystem::Draw(m_texture, m_destination);
	}

private:
	SDL_Texture * m_texture;
	SDL_Color m_colour;
	SDL_Rect m_destination;
	string m_text;
	TTF_Font * m_font;
	int m_offset;
};