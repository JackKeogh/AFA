/// <summary>
/// This component will handle commands made by the user and AI.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>
#include "TransformComponent.h"

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

protected:
	// Constructor
	Command() {};
};

class MoveLeft : public Command
{
	void Execute(TransformComponent * T) override
	{
		cout << "Moving Left..." << endl;
	}
};

class MoveRight : public Command
{
	void Execute(TransformComponent * T) override
	{
		cout << "Moving Right..." << endl;
	}
};

class Jump : public Command
{
	void Execute(TransformComponent * T) override
	{
		cout << "Jumping..." << endl;
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
