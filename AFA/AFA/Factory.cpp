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