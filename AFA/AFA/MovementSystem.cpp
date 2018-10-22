#include "MovementSystem.h"

float MovementSystem::m_friction = 0.9f;
float MovementSystem::m_gravity = 0.981f;

void MovementSystem::Move(vector<jk::Entity*>& entities)
{
	for (jk::Entity * ent : entities)
	{
		if (ent->getComponent<TransformComponent>().acceleration.Magnitude() != 0)
		{
			ent->getComponent<TransformComponent>().acceleration.x *= m_friction;
			ent->getComponent<TransformComponent>().acceleration.y *= m_gravity;
		}

		ent->getComponent<TransformComponent>().velocity = ent->getComponent<TransformComponent>().acceleration * ent->getComponent<TransformComponent>().speed;
		ent->getComponent<TransformComponent>().position += ent->getComponent<TransformComponent>().velocity;
	}
}