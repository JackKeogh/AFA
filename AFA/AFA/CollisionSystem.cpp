#include "CollisionSystem.h"

void CollisionSystem::TileCollision(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	bool bottom = false;
	float diffB = 0.0f;

	bool right = false;
	float diffR = 0.0f;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getBottom(), tile->getComponent<RigidbodyComponent>().getTop()))
			{
				diffB = (ent->getComponent<TransformComponent>().position.y + ent->getComponent<TransformComponent>().height) - tile->getComponent<TransformComponent>().position.y;
				bottom = true;
			}

			if (AABB(ent->getComponent<RigidbodyComponent>().getRight(), tile->getComponent<RigidbodyComponent>().getLeft()))
			{
				diffR = (ent->getComponent<TransformComponent>().position.x + ent->getComponent<TransformComponent>().width) - tile->getComponent<TransformComponent>().position.x;
				right = true;
			}
		}

		if (bottom)
		{
			if (!ent->getComponent<TransformComponent>().in_air)
			{
				ent->getComponent<TransformComponent>().position.y -= diffB;
			}
			ent->getComponent<RigidbodyComponent>().setGravity(false);
			ent->getComponent<TransformComponent>().in_air = false;
			ent->getComponent<TransformComponent>().velocity.y = 0;
		}
		else
		{
			ent->getComponent<RigidbodyComponent>().setGravity(true);
		}
		
		if (right)
		{
			ent->getComponent<TransformComponent>().position.x += diffR;
			ent->getComponent<TransformComponent>().velocity.x = 0;
		}
	}
}

bool CollisionSystem::AABB(SDL_Rect A, SDL_Rect B)
{
	if ((A.x >= B.x && A.x <= B.x + B.w) ||
		(A.x + A.w >= B.x && A.x + A.w <= B.x + B.w))
	{
		if ((A.y >= B.y && A.y <= B.y + B.h) ||
			(A.y + A.h >= B.y && A.y + A.h <= B.y + B.h))
		{
			return true;
		}
	}

	return false;
}
