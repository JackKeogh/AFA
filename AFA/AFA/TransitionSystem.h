#pragma once
#include "stdafx.h"
#include "RenderSystem.h"

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
	{
		m_box = new Box;
		m_box->rect = SDL_Rect{0, 0, 1260, 720};
		m_box->color.a = 255;
	};

	/// <summary>
	/// Default Deconstructor
	/// </summary>
	~TransitionSystem() 
	{
		delete m_box;
	};

	/// <summary>
	/// FadeIn
	/// 
	/// This function draws a black cube the size
	/// of the window and reduces it's alpha over time.
	/// </summary>
	/// <param name="delta_time">A float variable for delta time.</param>
	void FadeIn();

	/// <summary>
	/// FadeOut
	/// 
	/// This function draws a black cube the size of
	/// the window and increases it's alpha over time.
	/// </summary>
	/// <param name="delta_time">A float variable for delta time.</param>
	void FadeOut();

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

	/// <summary>
	/// setAlpha
	/// 
	/// This functions sets the alpha of the box's colour.
	/// </summary>
	void setAlpha(Uint8 a) { m_box->color.a = a; };

private:
	bool m_complete;
	Box * m_box;
};