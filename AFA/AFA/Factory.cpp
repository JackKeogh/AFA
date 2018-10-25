#include "Factory.h"

void TileFactory::CreateEntity(EntityManager * EManager, string Texture, float x, float y,
	float w, float h)
{
	auto& ent = EManager->addEntity();
	ent.addComponent<TransformComponent>(Vector2f(60 * x, y), 60, 64);
	ent.addComponent<SpriteComponent>(Texture, w, h);
	ent.addComponent<RigidbodyComponent>(false);
	ent.addLayer(jk::Layers::Middleground);
	ent.addGroup(jk::Groups::TileGroup);
}