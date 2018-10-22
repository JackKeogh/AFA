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
	RigidbodyComponent()
	{

	};

	~RigidbodyComponent()
	{

	};

	void Init() override
	{

	};

	void Update() override
	{

	};

	bool UsingGravity()
	{

	};

	SDL_Rect getCollider()
	{

	};

private:
	TransformComponent * m_transform;
	SDL_Rect m_collider;
	bool use_gravity;
};