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
	static bool left;
	static bool right;
	static bool top;
	static bool bottom;

	static void TileTAB(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities); // Top And Bottom
	static void TileLAR(vector<jk::Entity*>& tiles, vector<jk::Entity*>& entities); // Left And Right
	static bool AABB(SDL_Rect A, SDL_Rect B);
};