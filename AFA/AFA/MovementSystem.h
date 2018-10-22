/// <summary>
/// This class will be used to update entities in relation to their
/// acceleration and velocity variables; thus moving them.
/// </summary>

#pragma once
#include "stdafx.h"
#include "Components.h"

class MovementSystem
{
public:
	static void Move(vector<jk::Entity*>& entities);

private:
	static float m_gravity;
	static float m_friction;
};