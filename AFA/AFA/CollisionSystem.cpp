#include "CollisionSystem.h"

void CollisionSystem::TileCollision(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	bool collision = false;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getCollider(), tile->getComponent<RigidbodyComponent>().getCollider()))
			{
				collision = true;
			}
		}

		if (collision)
		{
			ent->getComponent<RigidbodyComponent>().setGravity(false);
			ent->getComponent<TransformComponent>().velocity.y = 0;
		}
		else
		{
			ent->getComponent<RigidbodyComponent>().setGravity(true);
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
