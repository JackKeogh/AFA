#include "CollisionSystem.h"

bool CollisionSystem::left = false;
bool CollisionSystem::right = false;
bool CollisionSystem::top = false;
bool CollisionSystem::bottom = false;

void CollisionSystem::TileTAB(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	top = false;
	bottom = false;
	float position = 0.0f;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getBottom(), tile->getComponent<RigidbodyComponent>().getCentral()))
			{
				position = tile->getComponent<RigidbodyComponent>().getTop().y - ent->getComponent<TransformComponent>().height;
				bottom = true;
			}

			if (!left || !right)
			{
				if (AABB(ent->getComponent<RigidbodyComponent>().getTop(), tile->getComponent<RigidbodyComponent>().getCentral()))
				{
					top = true;
					position = tile->getComponent<RigidbodyComponent>().getBottom().y + tile->getComponent<RigidbodyComponent>().getBottom().h;
				}
			}
		}

		if (bottom)
		{
			if (!ent->getComponent<TransformComponent>().in_air)
			{
				ent->getComponent<TransformComponent>().position.y = position;
			}
			ent->getComponent<CommandComponent>().getCommand("Right")->setEnabled(true);
			ent->getComponent<CommandComponent>().getCommand("Left")->setEnabled(true);
			ent->getComponent<CommandComponent>().getCommand("Jump")->setEnabled(true);
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
			ent->getComponent<TransformComponent>().position.y = position;
			ent->getComponent<TransformComponent>().jumpSpeed = 0.0f;
			ent->getComponent<TransformComponent>().velocity.y = 0;
		}
		
	}
}

void CollisionSystem::TileLAR(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities)
{
	right = false;
	left = false;
	float position = 0.0f;

	for (jk::Entity * ent : entities)
	{
		for (jk::Entity * tile : tiles)
		{
			if (AABB(ent->getComponent<RigidbodyComponent>().getRight(), tile->getComponent<RigidbodyComponent>().getLeft()) ||
				AABB(ent->getComponent<RigidbodyComponent>().getRight(), tile->getComponent<RigidbodyComponent>().getSmall()))
			{
				right = true;
				position = tile->getComponent<RigidbodyComponent>().getLeft().x - ent->getComponent<TransformComponent>().width - 4.0f;
			}

			else if (AABB(ent->getComponent<RigidbodyComponent>().getLeft(), tile->getComponent<RigidbodyComponent>().getRight()) ||
				AABB(ent->getComponent<RigidbodyComponent>().getLeft(), tile->getComponent<RigidbodyComponent>().getSmall()))
			{
				left = true;
				position = tile->getComponent<RigidbodyComponent>().getRight().x + tile->getComponent<RigidbodyComponent>().getRight().w + 4.0f;
			}
		}

		if (right)
		{
			ent->getComponent<CommandComponent>().getCommand("Right")->setEnabled(false);
			ent->getComponent<TransformComponent>().position.x = position;
			ent->getComponent<TransformComponent>().velocity.x = 0;
		}

		if (left)
		{
			ent->getComponent<CommandComponent>().getCommand("Left")->setEnabled(false);
			ent->getComponent<TransformComponent>().position.x = position;
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
