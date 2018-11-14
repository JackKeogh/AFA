#include "Factory.h"

void TileFactory::CreateEntity(EntityManager * EManager, const char * Texture, float x, float y,
	float w, float h, int lives)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 60, 64);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(false, 1.0f);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::TileGroup);
}

void TileFactory::CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x, float y, float w, float h, int lives)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 60, 64);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(false, 1.0f);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::TileGroup);
}

void PlayerFactory::CreateEntity(EntityManager * EManager, const char * Texture, float x, float y, float w, float h, int lives)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 32, 32, 0, 1, 5, 5);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<CommandComponent>();
	ent.addComponent<KeyComponent>();
	ent.addComponent<StatComponent>();
	ent.addComponent<RigidbodyComponent>(true, 1.0f);
	ent.addGroup(jk::Groups::PlayerGroup);
	ent.addLayer(jk::Layers::Middleground);

	ent.getComponent<StatComponent>().setLives(lives);
}

void ItemFactory::CreateEntity(EntityManager * EManager, const char * Texture, float x, float y, float w, float h, int lives)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 22, 25);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(true, 1.0f);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::ItemGroup);
}

void ItemFactory::CreateEntity(EntityManager * EManager, SDL_Texture * Texture, float x, float y, float w, float h, int lives)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 22, 25);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(false, 1.0f);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::TileGroup);
}