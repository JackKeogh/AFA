/// <summary>
/// This class creates a collider around the object it is attached to 
/// and will judge if gravity should be used or not.
/// </summary>

#pragma once
#include "stdafx.h"
#include "ECS.h"
#include "TransformComponent.h"
#include "RenderSystem.h"

class RigidbodyComponent : public Component
{
public:
	/// <summary>
	/// Rigidbody Component
	/// 
	/// Default constructor.
	/// </summary>
	RigidbodyComponent(bool s, float o = 0.0f) :
		use_gravity(s), m_offset(o)
	{
		m_central = SDL_Rect{ 0, 0, 0, 0 };
		m_left = SDL_Rect{ 0, 0, 0, 0 };
		m_right = SDL_Rect{ 0, 0, 0, 0 };
		m_top = SDL_Rect{ 0, 0, 0, 0 };
		m_bottom = SDL_Rect{ 0, 0, 0, 0 };

		Show = true;
	};

	/// <summary>
	/// ~Rigidbody Component
	/// 
	/// Default destuctor.
	/// </summary>
	~RigidbodyComponent()
	{
	};

	/// <summary>
	/// Init
	/// 
	/// Override for initialiser function of component class.
	/// </summary>
	void Init() override
	{
		m_transform = &m_entity->getComponent<TransformComponent>();

		// Central collider
		m_central.x = m_transform->position.x;
		m_central.y = m_transform->position.y;
		m_central.w = m_transform->width * m_transform->scale;
		m_central.h = m_transform->height * m_transform->scale;

		// Left Collider
		m_left.x = m_transform->position.x - m_offset;
		m_left.y = m_transform->position.y + m_offset;
		m_left.w = m_transform->width * m_transform->scale;
		m_left.h = m_transform->height * m_transform->scale - m_offset;

		// Right Collider
		m_right.x = m_transform->position.x + m_offset;
		m_right.y = m_transform->position.y + m_offset;
		m_right.w = m_transform->width * m_transform->scale;
		m_right.h = m_transform->height * m_transform->scale - m_offset;

		// Top Collider
		m_top.x = m_transform->position.x;
		m_top.y = m_transform->position.y - m_offset;
		m_top.w = m_transform->width * m_transform->scale;
		m_top.h = m_transform->height * m_transform->scale;

		cout << m_top.w << endl;

		// Bottom Collider
		m_bottom.x = m_transform->position.x;
		m_bottom.y = m_transform->position.y + m_offset;
		m_bottom.w = m_transform->width * m_transform->scale;
		m_bottom.h = m_transform->height * m_transform->scale;
	};

	/// <summary>
	/// Update
	/// 
	/// Override for update function of component class.
	/// </summary>
	void Update() override
	{
		// Central collider
		m_central.x = m_transform->position.x;
		m_central.y = m_transform->position.y;
		m_central.w = m_transform->width * m_transform->scale;
		m_central.h = m_transform->height * m_transform->scale;

		// Left Collider
		m_left.x = m_transform->position.x - m_offset;
		m_left.y = m_transform->position.y + m_offset;
		m_left.w = m_transform->width * m_transform->scale;
		m_left.h = m_transform->height * m_transform->scale - m_offset;

		// Right Collider
		m_right.x = m_transform->position.x + m_offset;
		m_right.y = m_transform->position.y + m_offset;
		m_right.w = m_transform->width * m_transform->scale;
		m_right.h = m_transform->height * m_transform->scale - m_offset;

		// Top Collider
		m_top.x = m_transform->position.x - m_offset;
		m_top.y = m_transform->position.y - m_offset;
		m_top.w = (m_offset * 2) + m_transform->width * m_transform->scale;
		m_top.h = m_transform->height * m_transform->scale;

		cout << m_top.w << endl;

		// Bottom Collider
		m_bottom.x = m_transform->position.x;
		m_bottom.y = m_transform->position.y + m_offset;
		m_bottom.w = m_transform->width * m_transform->scale;
		m_bottom.h = m_transform->height * m_transform->scale;
	};

	void Render() override
	{
		if (Show)
		{
			RenderSystem::Draw(m_top);
			RenderSystem::Draw(m_right);
			RenderSystem::Draw(m_left);
			RenderSystem::Draw(m_bottom);
		}
	}

	/// <summary>
	/// Using Gravity
	/// 
	/// Checks if the component has gravity turned on or off.
	/// </summary>
	/// <returns>A bool value.</returns>
	bool UsingGravity()
	{
		return use_gravity;
	};

	/// <summary>
	/// Set Gravity
	/// 
	/// Sets the use_gravity variable.
	/// </summary>
	/// <param name="value">A bool value.</param>
	void setGravity(bool value)
	{
		use_gravity = value;
	}

	/// <summary>
	/// Get Central
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getCentral()
	{
		return m_central;
	};

	/// <summary>
	/// Get Left
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getLeft()
	{
		return m_left;
	};

	/// <summary>
	/// Get Right
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getRight()
	{
		return m_right;
	};

	/// <summary>
	/// Get Top
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getTop()
	{
		return m_top;
	};

	/// <summary>
	/// Get Bottom
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getBottom()
	{
		return m_bottom;
	};

private:
	TransformComponent * m_transform;
	SDL_Rect m_bottom;
	SDL_Rect m_top;
	SDL_Rect m_left;
	SDL_Rect m_right;
	SDL_Rect m_central;
	float m_offset;
	bool use_gravity;
	bool Show;
};