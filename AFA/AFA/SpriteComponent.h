/// <summary>
/// This class uses a reference to 
/// the transform component to draw
/// an sdl_texture at a particular 
/// position.
/// </summary>

#pragma once
#include "stdafx.h"
#include "RenderSystem.h"
#include "TransformComponent.h"

using namespace jk;

class SpriteComponent : public Component
{
private:
	TransformComponent * m_transform;
	SDL_Rect m_distRect;
	SDL_Rect m_srcRect;
	SDL_Texture * m_texture;
	float rotation;

public:
	/// <summary>
	///Overload constructor that defaults values to 0
	/// </summary>
	/// <param name="path">const char ptr defining path to texture.</param>
	/// <param name="w">int to define src rect width.</param>
	/// <param name="h">int to define src rect height.</param>
	SpriteComponent(const char* path = "", int w = 0, int h = 0)
	{
		if (!(m_texture = IMG_LoadTexture(RenderSystem::Renderer(), path)))
		{
			cout << IMG_GetError << endl;
			cout << "Failed to Load Image..." << endl;
		}

		m_srcRect.w = w;
		m_srcRect.h = h;
	}

	/// <summary>
	/// Overload constructor that defaults values to 0.
	/// </summary>
	/// <param name="Texture">SDL_Texture ptr defining the texture.</param>
	/// <param name="w">int to define src rect width.</param>
	/// <param name="h">int to define src rect height.</param>
	SpriteComponent(SDL_Texture * Texture, int w = 0, int h = 0)
	{
		m_texture = Texture;

		m_srcRect.w = w;
		m_srcRect.h = h;
	}

	void Init() override
	{
		m_transform = &m_entity->getComponent<TransformComponent>();

		m_distRect.x = m_transform->position.x;
		m_distRect.y = m_transform->position.y;
		m_distRect.w = m_transform->width;
		m_distRect.h = m_transform->height;
		rotation = m_transform->rotation;
	}

	void Update() override
	{
		m_distRect.x = m_transform->position.x;
		m_distRect.y = m_transform->position.y;
		m_distRect.w = m_transform->width * m_transform->scale;
		m_distRect.h = m_transform->height * m_transform->scale;
		rotation = m_transform->rotation;
	}

	void Render() override
	{
		RenderSystem::Draw(m_texture, m_srcRect, m_distRect, rotation);
	}
};