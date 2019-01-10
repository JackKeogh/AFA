#pragma once
#include "stdafx.h"
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
	virtual void CreateEntity(EntityManager * EManager, const char * Texture = "", float x = 60, float y = 64,
		float w = 60, float h = 64, int lives = 3) {};
	virtual void CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x = 60, float y = 64,
		float w = 60, float h = 64, int lives = 3) {};

protected:
	Factory() {};
};

class TileFactory : public Factory
{
public:
	TileFactory() {};
	void CreateEntity(EntityManager * EManager, const char * Texture, float x = 60, float y = 64, float w = 60, float h = 64, int lives = 3) override;
	void CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x = 60, float y = 64, float w = 60, float h = 64, int lives = 3) override;
};

class PlayerFactory : public Factory
{
public:
	PlayerFactory() {};
	void CreateEntity(EntityManager * EManager, const char * Texture, float x = 60, float y = 64, float w = 60, float h = 64, int lives = 3) override;
};

class ItemFactory : public Factory
{
public:
	ItemFactory() {};
	void CreateEntity(EntityManager * EManager, const char * Texture, float x = 60, float y = 64, float w = 60, float h = 64, int lives = 3) override;
	void CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x = 60, float y = 64, float w = 60, float h = 64, int lives = 3) override;
};

class ImageFactory : public Factory
{
public:
	void CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x = 60, float y = 64,
		float w = 60, float h = 64, int lives = 3);
};