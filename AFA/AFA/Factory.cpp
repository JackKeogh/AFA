#include "Factory.h"

void TileFactory::CreateEntity(EntityManager * EManager, const char * Texture, float x, float y,
	float w, float h)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 60, 64);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(false, 2.0f);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::TileGroup);
}

void PlayerFactory::CreateEntity(EntityManager * EManager, const char * Texture, float x, float y, float w, float h)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(x, y), 50, 80, 0, 1, 5, 5);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<CommandComponent>();
	ent.addComponent<KeyComponent>();
	ent.addComponent<RigidbodyComponent>(true, 5.0f);
	ent.addGroup(jk::Groups::PlayerGroup);
	ent.addLayer(jk::Layers::Foreground);
}