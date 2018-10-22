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

	};

	/// <summary>
	/// Update
	/// 
	/// Override for update function of component class.
	/// </summary>
	void Update() override
	{

	};

	/// <summary>
	/// Using Gravity
	/// 
	/// Checks if the component has gravity turned on or off.
	/// </summary>
	/// <returns>A bool value.</returns>
	bool UsingGravity()
	{

	};

	/// <summary>
	/// Get Collider
	/// 
	/// A getter function to get the collider.
	/// </summary>
	/// <returns>A SDL_Rect value.</returns>
	SDL_Rect getCollider()
	{

	};

private:
	TransformComponent * m_transform;
	SDL_Rect m_collider;
	bool use_gravity;
};