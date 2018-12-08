/// <summary>
/// This Component will be used in conjuction with the sprite component
/// in order to animate tiles.
/// </summary>

#pragma once
#include "stdafx.h"
#include "SpriteComponent.h"

enum class Animations : size_t
{
	IdleRight = 0,
	IdleLeft,
	RunRight,
	RunLeft,
	Jumping,
	Falling
};

struct Animation
{
	int m_currentFrame;
	int m_maxFrames;
	int m_width;
	int m_height;
	int m_position;
	float m_time;

	Animation(int MaxFrames, int Width, int Height, float Time) :
		m_currentFrame(0), m_maxFrames(MaxFrames), m_width(Width),
		m_height(Height), m_position(0), m_time(Time)
	{};
};

class State;

class AnimationComponent : public Component
{
public:
	/// <summary>
	/// Animation Component
	/// 
	/// Default constructor for the animation component.
	/// </summary>
	AnimationComponent()
	{};

	/// <summary>
	/// ~Animation Component
	/// 
	/// Default destructor for the animation component.
	/// </summary>
	~AnimationComponent()
	{};

	/// <summary>
	/// Init
	/// 
	/// Override for component initialiser.
	/// </summary>
	void Init() override;

	/// <summary>
	/// Update
	/// 
	/// Override for component's update method.
	/// </summary>
	void Update() override;

	/// <summary>
	/// Add Animation
	/// 
	/// Adds a new animation to the Animation Component FSM.
	/// </summary>
	void addAnimation(Animations A, int F, int W, int H, float T)
	{
		m_animations[A] = new Animation(F, W, H, T);
	};

	/// <summary>
	/// Set State
	/// 
	/// Sets the current animation state.
	/// </summary>
	/// <param name="s">The Animations State to change too.</param>
	void SetState(State * s);

	/// <summary>
	/// Idle Right
	/// 
	/// Current State gets set to Idle Right.
	/// </summary>
	void IdleRight();

	/// <summary>
	/// Idle Left
	/// 
	/// Current State gets set to Idle Left.
	/// </summary>
	void IdleLeft();

	/// <summary>
	/// Run Right
	/// 
	/// Current State gets set to Run Right.
	/// </summary>
	void RunRight();

	/// <summary>
	/// Run Left
	/// 
	/// Current State gets set to Run Right.
	/// </summary>
	void RunLeft();

private:
	State * m_currentState;
	Animations m_currentAnimation;
	map<Animations, Animation*> m_animations;
	SpriteComponent * m_sprite;
	TransformComponent * m_transform;
	float m_timer;
};

class State
{
public:
	virtual void IdleRight(AnimationComponent * A) {};
	
	virtual void IdleLeft(AnimationComponent * A) {};

	virtual void RunRight(AnimationComponent * A) {};

	virtual void RunLeft(AnimationComponent * A) {};

	virtual void jump(AnimationComponent * A) {};

	virtual void Animate(SpriteComponent * S, TransformComponent * T, Animation * A, AnimationComponent * AC) {};

};

class IdleRightState : public State
{
public:
	/// <summary>
	/// Idle
	/// 
	/// Default constructor for Idle State.
	/// </summary>
	IdleRightState() {};

	/// <summary>
	/// ~Idle
	/// 
	/// Default destructor for Idle State.
	/// </summary>
	~IdleRightState() {};

	/// <summary>
	/// Idle Left
	/// 
	/// Changes the animation state to idle left.
	/// </summary>
	void IdleLeft(AnimationComponent * A) override;

	/// <summary>
	/// Run Right
	/// 
	/// Change the animation state to run right.
	/// </summary>
	void RunRight(AnimationComponent * A) override;

	/// <summary>
	/// Run Left
	/// 
	/// Change the animation state to run left.
	/// </summary>
	void RunLeft(AnimationComponent * A) override;

	/// <summary>
	/// Animate
	/// 
	/// Override animate function to preform Idle animation.
	/// </summary>
	/// <param name="S">SpriteComponent of the entity.</param>
	/// <param name="T">TransformComponent of the entity.</param>
	/// <param name="A">Animation playing.</param>
	void Animate(SpriteComponent * S, TransformComponent * T, Animation * A, AnimationComponent * AC) override
	{
		if (T->acceleration.x > 0.0f)
		{
			RunRight(AC);
		}
		else if (T->acceleration.x < 0.0f)
		{
			RunLeft(AC);
		}

		if (A->m_currentFrame < A->m_maxFrames)
		{
			A->m_currentFrame += 1;
		}
		else
		{
			A->m_currentFrame = 0;
		}

		A->m_position = A->m_width * A->m_currentFrame;

		S->setSheetPosition(A->m_position, A->m_height);
	};
};

class IdleLeftState : public State
{
public:
	/// <summary>
	/// Idle Left State
	/// 
	/// Default constructor for Idle Left State.
	/// </summary>
	IdleLeftState() {};

	/// <summary>
	/// ~Idle Left State
	/// 
	/// Default destructor for Idle State.
	/// </summary>
	~IdleLeftState() {};

	/// <summary>
	/// Idle Right
	/// 
	/// Changes the animation state to idle left.
	/// </summary>
	void IdleRight(AnimationComponent * A) override;

	/// <summary>
	/// Run Right
	/// 
	/// Cahnge the animation state to run right.
	/// </summary>
	void RunRight(AnimationComponent * A) override;

	/// <summary>
	/// Run Left
	/// 
	/// Change the animation state to run left.
	/// </summary>
	void RunLeft(AnimationComponent * A) override;

	/// <summary>
	/// Animate
	/// 
	/// Override animate function to preform Idle animation.
	/// </summary>
	/// <param name="S">SpriteComponent of the entity.</param>
	/// <param name="T">TransformComponent of the entity.</param>
	/// <param name="A">Animation playing.</param>
	void Animate(SpriteComponent * S, TransformComponent * T, Animation * A, AnimationComponent * AC) override
	{
		if (T->acceleration.x > 0.0f)
		{
			RunRight(AC);
		}
		else if (T->acceleration.x < -0.0f)
		{
			RunLeft(AC);
		}

		if (A->m_currentFrame < A->m_maxFrames)
		{
			A->m_currentFrame += 1;
		}
		else
		{
			A->m_currentFrame = 0;
		}

		A->m_position = A->m_width * A->m_currentFrame;

		S->setSheetPosition(A->m_position, A->m_height);
	};
};

class RunRightState : public State
{
public:
	/// <summary>
	/// Idle Left State
	/// 
	/// Default constructor for Idle Left State.
	/// </summary>
	RunRightState() {};

	/// <summary>
	/// ~Idle Left State
	/// 
	/// Default destructor for Idle State.
	/// </summary>
	~RunRightState() {};

	/// <summary>
	/// Idle Right
	/// 
	/// Changes the animation state to idle left.
	/// </summary>
	void IdleRight(AnimationComponent * A) override;

	/// <summary>
	/// Run Left
	/// 
	/// Change the animation state to run left.
	/// </summary>
	void RunLeft(AnimationComponent * A) override;

	/// <summary>
	/// Animate
	/// 
	/// Override animate function to preform Idle animation.
	/// </summary>
	/// <param name="S">SpriteComponent of the entity.</param>
	/// <param name="T">TransformComponent of the entity.</param>
	/// <param name="A">Animation playing.</param>
	void Animate(SpriteComponent * S, TransformComponent * T, Animation * A, AnimationComponent * AC) override
	{
		if (T->velocity.x >= -0.01f && T->velocity.x <= 0.01f)
		{
			IdleRight(AC);
		}

		if (T->acceleration.x < -0.0f)
		{
			RunLeft(AC);
		}

		if (A->m_currentFrame < A->m_maxFrames)
		{
			A->m_currentFrame += 1;
		}
		else
		{
			A->m_currentFrame = 0;
		}

		A->m_position = A->m_width * A->m_currentFrame;

		S->setSheetPosition(A->m_position, A->m_height);
	};
};

class RunLeftState : public State
{
public:
	/// <summary>
	/// Idle Left State
	/// 
	/// Default constructor for Idle Left State.
	/// </summary>
	RunLeftState() {};

	/// <summary>
	/// ~Idle Left State
	/// 
	/// Default destructor for Idle State.
	/// </summary>
	~RunLeftState() {};

	/// <summary>
	/// Idle Right
	/// 
	/// Changes the animation state to idle left.
	/// </summary>
	void IdleLeft(AnimationComponent * A) override;

	/// <summary>
	/// Run Right
	/// 
	/// Cahnge the animation state to run right.
	/// </summary>
	void RunRight(AnimationComponent * A) override;

	/// <summary>
	/// Animate
	/// 
	/// Override animate function to preform Idle animation.
	/// </summary>
	/// <param name="S">SpriteComponent of the entity.</param>
	/// <param name="T">TransformComponent of the entity.</param>
	/// <param name="A">Animation playing.</param>
	void Animate(SpriteComponent * S, TransformComponent * T, Animation * A, AnimationComponent * AC) override
	{
		if (T->velocity.x >= -0.01f && T->velocity.x <= 0.01f)
		{
			IdleLeft(AC);
		}

		if (T->acceleration.x > 0.0f)
		{
			RunRight(AC);
		}

		if (A->m_currentFrame < A->m_maxFrames)
		{
			A->m_currentFrame += 1;
		}
		else
		{
			A->m_currentFrame = 0;
		}

		A->m_position = A->m_width * A->m_currentFrame;

		S->setSheetPosition(A->m_position, A->m_height);
	};
};