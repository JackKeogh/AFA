#include "MovementSystem.h"

float MovementSystem::m_friction = 0.9f;
float MovementSystem::m_gravity = 9.81f;

void MovementSystem::Move(vector<jk::Entity*>& entities, float delta_time)
{
	for (jk::Entity * ent : entities)
	{
		if (ent->getComponent<RigidbodyComponent>().UsingGravity())
		{
			if (!(ent->getComponent<TransformComponent>().in_air))
			{
				ent->getComponent<TransformComponent>().velocity.y += m_gravity * delta_time;
			}
			else
			{
				ent->getComponent<TransformComponent>().jumpSpeed += m_gravity;
				ent->getComponent<TransformComponent>().velocity.y = ent->getComponent<TransformComponent>().jumpSpeed * delta_time;
			}
		}

		if (ent->getComponent<TransformComponent>().acceleration.x != 0)
		{
			ent->getComponent<TransformComponent>().acceleration.x *= m_friction;
		}

		ent->getComponent<TransformComponent>().velocity.x = (ent->getComponent<TransformComponent>().acceleration.x * ent->getComponent<TransformComponent>().speed);

		ent->getComponent<TransformComponent>().position += ent->getComponent<TransformComponent>().velocity;
	}
}