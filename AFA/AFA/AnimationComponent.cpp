#include "AnimationComponent.h"

void AnimationComponent::Init()
{
	m_sprite = &m_entity->getComponent<SpriteComponent>();
	m_transform = &m_entity->getComponent<TransformComponent>();
	m_currentAnimation = Animations::IdleRight;
	m_currentState = new IdleRightState;
}

void AnimationComponent::Update()
{
	m_timer += 1.0f / 60.0f;

	if (m_animations.size() != 0)
	{
		if (m_timer >= m_animations[m_currentAnimation]->m_time)
		{
			m_currentState->Animate(m_sprite, m_transform, m_animations[m_currentAnimation], this);
			m_timer = 0.0f;
		}
	}
}

void AnimationComponent::SetState(State * s)
{
	m_currentState = s;
}

void AnimationComponent::IdleRight()
{
	m_currentAnimation = Animations::IdleRight;
	m_sprite->setSheetPosition(0, 0);
}

void AnimationComponent::IdleLeft()
{
	m_currentAnimation = Animations::IdleLeft;
	m_sprite->setSheetPosition(0, 46);
}

void AnimationComponent::RunRight()
{
	m_currentAnimation = Animations::RunRight;
	m_sprite->setSheetPosition(0, 92);
}

void AnimationComponent::RunLeft()
{
	m_currentAnimation = Animations::RunLeft;
	m_sprite->setSheetPosition(0, 138);
}

////////////////////////////////////////////////////////////////////////////

void IdleLeftState::IdleRight(AnimationComponent * A)
{
	A->IdleRight();
	A->SetState(new IdleRightState);

	delete this;
}


void IdleLeftState::RunRight(AnimationComponent * A)
{
	A->RunRight();
	A->SetState(new RunRightState);

	delete this;
}

void IdleLeftState::RunLeft(AnimationComponent * A)
{
	A->RunLeft();
	A->SetState(new RunLeftState);

	delete this;
}

////////////////////////////////////////////////////////////////////////////

void IdleRightState::IdleLeft(AnimationComponent * A)
{
	A->IdleLeft();
	A->SetState(new IdleLeftState);

	delete this;
}

void IdleRightState::RunRight(AnimationComponent * A)
{
	A->RunRight();
	A->SetState(new RunRightState);

	delete this;
}

void IdleRightState::RunLeft(AnimationComponent * A)
{
	A->RunLeft();
	A->SetState(new RunLeftState);

	delete this;
}

////////////////////////////////////////////////////////////////////////////

void RunRightState::IdleRight(AnimationComponent * A)
{
	A->IdleRight();
	A->SetState(new IdleRightState);

	delete this;
}

void RunRightState::RunLeft(AnimationComponent * A)
{
	A->RunLeft();
	A->SetState(new RunLeftState);

	delete this;
}

////////////////////////////////////////////////////////////////////////////

void RunLeftState::IdleLeft(AnimationComponent * A)
{
	A->IdleLeft();
	A->SetState(new IdleLeftState);

	delete this;
}

void RunLeftState::RunRight(AnimationComponent * A)
{
	A->RunRight();
	A->SetState(new RunRightState);

	delete this;
}
