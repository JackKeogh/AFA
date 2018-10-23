#include "InputSystem.h"

InputSystem::InputSystem()
{
	m_jump = m_left = m_right = false;
}

InputSystem::~InputSystem()
{}

void InputSystem::KeyPressed(SDL_Event e, vector<jk::Entity *>& entities)
{
	if (e.type == SDL_KEYDOWN)
	{
		for (jk::Entity * ent : entities)
		{
			if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Left())
			{
				m_left = true;
			}
			else if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Right())
			{
				m_right = true;
			}
			else if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Jump())
			{
				m_jump = true;
			}
		}
	}
}

void InputSystem::KeyReleased(SDL_Event e, vector<jk::Entity*>& entities)
{
	if (e.type == SDL_KEYUP)
	{
		for (jk::Entity * ent : entities)
		{
			if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Left())
			{
				m_left = false;
			}
			else if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Right())
			{
				m_right = false;
			}
			else if (e.key.keysym.sym == ent->getComponent<KeyComponent>().Jump())
			{
				m_jump = false;
			}
		}
	}
}

void InputSystem::Update(jk::EntityManager * Manager, vector<jk::Entity*>& entities)
{
	for (jk::Entity* ent : entities)
	{
		if (m_left)
		{
			ent->getComponent<CommandComponent>().getCommand("Left")->Execute(&ent->getComponent<TransformComponent>());
		}

		if (m_right)
		{
			ent->getComponent<CommandComponent>().getCommand("Right")->Execute(&ent->getComponent<TransformComponent>());
		}
		
		if (m_jump)
		{
			ent->getComponent<CommandComponent>().getCommand("Jump")->Execute(&ent->getComponent<TransformComponent>(), &ent->getComponent<RigidbodyComponent>());
		}
		else
		{
			ent->getComponent<TransformComponent>().acceleration.y = 0.0f;
		}
	}
}