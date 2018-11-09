#include "TransitionSystem.h"

void TransitionSystem::FadeIn()
{
	if (m_box->color.a > 0)
	{
		m_box->color.a -= 1.0f;
	}
	else
	{
		m_complete = true;
	}
	RenderSystem::Draw(m_box);
}

void TransitionSystem::FadeOut()
{
	if (m_box->color.a < 255)
	{
		m_box->color.a += 1.0f;
	}
	else
	{
		m_complete = true;
	}
	RenderSystem::Draw(m_box);
}