#include "MovementSystem.h"

float MovementSystem::m_friction = 0.9f;
float MovementSystem::m_gravity = 0.981f;

void MovementSystem::Move(vector<jk::Entity*>& entities)
{
	for (jk::Entity * ent : entities)
	{
		ent->getComponent<TransformComponent>().acceleration.x *= m_friction;

		ent->getComponent<TransformComponent>().velocity.x += ent->getComponent<TransformComponent>().acceleration.x * ent->getComponent<TransformComponent>().speed;


		ent->getComponent<TransformComponent>().position += ent->getComponent<TransformComponent>().velocity;
	}
}