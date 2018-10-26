#include "CollisionSystem.h"

bool CollisionSystem::left = false;
bool CollisionSystem::right = false;
bool CollisionSystem::top = false;
bool CollisionSystem::bottom = false;

void CollisionSystem::TileTAB(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	bottom = false;
	float diffB = 0.0f;

	top = false;
	float diffT = 0.0f;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getBottom(), tile->getComponent<RigidbodyComponent>().getTop()))
			{
				diffB = (ent->getComponent<TransformComponent>().position.y + ent->getComponent<TransformComponent>().height) - tile->getComponent<TransformComponent>().position.y;
				bottom = true;
			}

			if (!left || !right)
			{
				if (AABB(ent->getComponent<RigidbodyComponent>().getTop(), tile->getComponent<RigidbodyComponent>().getBottom()))
				{
					top = true;
					diffT = ent->getComponent<TransformComponent>().position.y - 
						(tile->getComponent<TransformComponent>().position.y + tile->getComponent<TransformComponent>().height);
				}
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
		
		if (top)
		{
			ent->getComponent<TransformComponent>().position.y += diffT;
			ent->getComponent<TransformComponent>().velocity.y = 0;
		}
		
	}
}

void CollisionSystem::TileLAR(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	right = false;
	float diffR = 0.0f;

	left = false;
	float diffL = 0.0f;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getRight(), tile->getComponent<RigidbodyComponent>().getLeft()))
			{
				diffR = (ent->getComponent<RigidbodyComponent>().getRight().x + ent->getComponent<RigidbodyComponent>().getRight().w) -
					tile->getComponent<RigidbodyComponent>().getLeft().x;
				right = true;
			}

			else if (AABB(ent->getComponent<RigidbodyComponent>().getLeft(), tile->getComponent<RigidbodyComponent>().getRight()))
			{
				diffL = (tile->getComponent<RigidbodyComponent>().getRight().x + tile->getComponent<RigidbodyComponent>().getRight().w)
					- ent->getComponent<RigidbodyComponent>().getLeft().x;
				left = true;
			}
		}

		if (right)
		{
			ent->getComponent<TransformComponent>().position.x -= diffR;
			ent->getComponent<TransformComponent>().velocity.x = 0;
		}

		if (left)
		{
			ent->getComponent<TransformComponent>().position.x += diffL;
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
