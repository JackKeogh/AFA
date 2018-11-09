#pragma once
#include "stdafx.h"
#include "RenderSystem.h"

/// <summary>
/// This struct contains a SDL_Rect and a Color variables.
/// </summary>

struct Color
{
	Uint8 r, g, b, a;
};

struct Box
{
	SDL_Rect rect;
	Color color;

	/// <summary>
	/// Default constructor
	/// </summary>
	Box()
	{
		rect = SDL_Rect{ 0, 0, 0, 0 };
		color = Color{ 0, 0, 0, 0 };
	}
};

/// <summary>
/// This class will be used to handle timings and transitions.
/// </summary>

class TransitionSystem
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	TransitionSystem() :
		m_complete(false)
	{};

	/// <summary>
	/// Default Deconstructor
	/// </summary>
	~TransitionSystem() {};

	/// <summary>
	/// FadeIn
	/// 
	/// This function draws a black cube the size
	/// of the window and reduces it's alpha over time.
	/// </summary>
	/// <param name="delta_time">A float variable for delta time.</param>
	void FadeIn(float delta_time);

	/// <summary>
	/// FadeOut
	/// 
	/// This function draws a black cube the size of
	/// the window and increases it's alpha over time.
	/// </summary>
	/// <param name="delta_time">A float variable for delta time.</param>
	void FadeOut(float delta_time);

	/// <summary>
	/// Reset
	/// 
	/// This function resets the Transition System.
	/// </summary>
	void Reset() { m_complete = false; };

	/// <summary>
	/// Transition
	/// 
	/// This function returns if the transition is complete or not.
	/// </summary>
	bool Transition() { return m_complete; };

private:
	bool m_complete;
};