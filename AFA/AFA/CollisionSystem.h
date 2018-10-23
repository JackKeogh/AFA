/// <summary>
/// This class will be used to check the collision between entities and 
/// issue the correct reaction.
/// </summary>

#pragma once
#include "stdafx.h"
#include "Components.h"

class CollisionSystem
{
public:
	static void TileCollision(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities);
	static bool CheckBelow(SDL_Rect A, SDL_Rect B);
	static bool AABB(SDL_Rect A, SDL_Rect B);
};