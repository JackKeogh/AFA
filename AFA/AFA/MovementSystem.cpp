#include "MovementSystem.h"

float MovementSystem::m_friction = 0.9f;
float MovementSystem::m_gravity = 0.981f;

void MovementSystem::Move(vector<jk::Entity*>& entities, float delta_time)
{
	for (jk::Entity * ent : entities)
	{
		if (ent->getComponent<RigidbodyComponent>().UsingGravity())
		{
			ent->getComponent<TransformComponent>().velocity.y += m_gravity * delta_time;
		}


		ent->getComponent<TransformComponent>().position += ent->getComponent<TransformComponent>().velocity;
	}
}