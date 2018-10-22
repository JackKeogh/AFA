/// <summary>
/// This class creates a collider around the object it is attached to 
/// and will judge if gravity should be used or not.
/// </summary>

#pragma once
#include "stdafx.h"
#include "ECS.h"
#include "TransformComponent.h"

class RigidbodyComponent : public Component
{
public:
	/// <summary>
	/// Rigidbody Component
	/// 
	/// Default constructor.
	/// </summary>
	RigidbodyComponent()
	{
		use_gravity = false;
		m_collider = SDL_Rect{ 0, 0, 0, 0 };
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

		m_collider.x = m_transform->position.x;
		m_collider.y = m_transform->position.y;
		m_collider.w = m_transform->width * m_transform->scale;
		m_collider.h = m_transform->height * m_transform->scale;
	};

	/// <summary>
	/// Update
	/// 
	/// Override for update function of component class.
	/// </summary>
	void Update() override
	{
		m_collider.x = m_transform->position.x;
		m_collider.y = m_transform->position.y;
		m_collider.w = m_transform->width * m_transform->scale;
		m_collider.h = m_transform->height * m_transform->scale;
	};

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
	/// Get Collider
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getCollider()
	{
		return m_collider;
	};

private:
	TransformComponent * m_transform;
	SDL_Rect m_collider;
	bool use_gravity;
};