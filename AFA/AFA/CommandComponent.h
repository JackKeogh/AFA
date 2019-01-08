/// <summary>
/// This component will handle commands made by the user and AI.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>
#include "TransformComponent.h"
#include "Rigidbody.h"
#include "AnimationComponent.h"

class Command
{
public:
	// Destructor
	virtual ~Command() {};

	/// <summary>
	/// Execute
	/// 
	/// This function executes the necessary update for
	/// the command.
	/// </summary>
	virtual void Execute(TransformComponent * T) {};

	/// <summary>
	/// Execute
	/// 
	/// This function executes the necessary update for
	/// the command.
	/// </summary>
	virtual void Execute(TransformComponent * T, AnimationComponent * A) {};

	/// <summary>
	/// Execute
	/// 
	/// This function executes the necessary update for the command.
	/// </summary>
	virtual void Execute(TransformComponent * T, RigidbodyComponent * R) {};

	/// <summary>
	/// Execute
	/// 
	/// This function executes the necessary update for the command.
	/// </summary>
	virtual void Execute(TransformComponent * T, RigidbodyComponent * R, AnimationComponent * A) {};

	/// <summary>
	/// Set Enabled
	/// 
	/// This function sets the enabled bool.
	/// </summary>
	void setEnabled(bool set) { enabled = set; };

	/// <summary>
	/// Enabled
	/// 
	/// This function returns if the command is enabled
	/// or disabled.
	/// </summary>
	bool Enabled() { return enabled; };

protected:
	// Constructor
	Command() 
	{
		enabled = true;
	};

	// Allow Commands to be disabled/enabled
	bool enabled;
};

class MoveLeft : public Command
{
	void Execute(TransformComponent * T) override
	{
		if (enabled)
		{
			T->acceleration.x -= 0.1f;

			if (T->acceleration.x < -T->MaxAccel)
			{
				T->acceleration.x = -T->MaxAccel;
			}
		}
	}

	void Execute(TransformComponent * T, AnimationComponent * A) override
	{
		if (enabled)
		{
			A->IdleLeft();

			T->acceleration.x -= 0.1f;

			if (T->acceleration.x < -T->MaxAccel)
			{
				T->acceleration.x = -T->MaxAccel;
			}
		}
	}
};

class MoveRight : public Command
{
	void Execute(TransformComponent * T) override
	{
		if (enabled)
		{
			T->acceleration.x += 0.1f;

			if (T->acceleration.x > T->MaxAccel)
			{
				T->acceleration.x = T->MaxAccel;
			}
		}
	}

	void Execute(TransformComponent * T, AnimationComponent * A) override
	{
		if (enabled)
		{
			A->IdleRight();

			T->acceleration.x += 0.1f;

			if (T->acceleration.x > T->MaxAccel)
			{
				T->acceleration.x = T->MaxAccel;
			}
		}
	};
};

class Jump : public Command
{
	void Execute(TransformComponent * T, RigidbodyComponent * R) override
	{
		if (enabled)
		{
			if (!(T->in_air))
			{
				T->jumpSpeed = -300;
				T->in_air = true;
				R->setGravity(true);
				enabled = false;
			}
		}
	}
};

class CommandComponent : public jk::Component
{
public:
	// Constructors
	CommandComponent() {};

	/// <summary>
	/// Init
	/// 
	/// The initialiser function for the Command Component.
	/// </summary>
	void Init() override
	{
		m_commands["Left"] = new MoveLeft;
		m_commands["Right"] = new MoveRight;
		m_commands["Jump"] = new Jump;
	}

	/// <summary>
	/// Get Command
	/// 
	/// This getter functions returns a particular command
	/// from the vector of commands.
	/// </summary>
	/// <param name="c">The command to return.</param>
	/// <returns>A Command ptr.</returns>
	Command * getCommand(string c)
	{
		return m_commands[c];
	}

private:
	map <string, Command*> m_commands;
};
