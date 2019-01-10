/// <summary>
/// This component keeps track of an entities lives
/// and heat variables
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>

class StatComponent : public jk::Component
{
public:

	/// <summary>
	/// Constructor
	/// </summary>
	StatComponent()
	{
	}

	/// <summary>
	/// Init
	/// 
	/// Override for component initialiser.
	/// </summary>
	void Init() override
	{
		m_lives = 3;
		m_heat = 20.f;
	}

	/// <summary>
	/// Update 
	/// 
	/// override for component update;
	/// </summary>
	void Update() override
	{
		//m_heat -= 1.0f * m_deltaTime;

		if (m_heat < 0.f)
		{
			m_lives--;
		}
	}

	/// <summary>
	/// setDeltaTime
	/// 
	/// function used to set delta time.
	/// </summary>
	void setDeltaTime(float set) { m_deltaTime = set; };

	/// <summary>
	/// setHeat
	/// 
	/// function used to set heat.
	/// </summary>
	void setHeat(float set) { m_heat = set; };

	/// <summary>
	/// setLives
	/// 
	/// function used to set lives.
	/// </summary>
	void setLives(int set) { m_lives = set; };

	/// <summary>
	/// getHeat
	/// 
	/// function used to get heat.
	/// </summary>
	float getHeat() { return m_heat; };

	/// <summary>
	/// getLives
	/// 
	/// function used to get lives.
	/// </summary>
	int getLives() { return m_lives; };

private:
	int m_lives;
	float m_heat;
	float m_deltaTime;
};
