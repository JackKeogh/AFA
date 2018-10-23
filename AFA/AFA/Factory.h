#pragma once
#include <iostream>
#include "AssetHandler.h"
#include "Components.h"

/// <class>Factory</class>
/// <summary>
/// This class will be a complete abstract class
/// for three other classes to inherit from. These
/// class will be used to create four different types
/// of entities with the corresponding components;
/// Player entity and Tile entity.
/// </summary>
/// <author>Jack Keogh & Jason Hannon</author>

class Factory
{
public:
	virtual void CreateEntity(EntityManager * EManager, SDL_Texture * Texture = nullptr, float x = 64, float y = 64,
		float w = 64, float h = 64) {};

protected:
	Factory() {};
	AssetHandler * m_assets;
};