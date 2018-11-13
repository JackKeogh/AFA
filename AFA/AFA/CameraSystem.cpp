#include "CameraSystem.h"

SDL_Rect CameraSystem::m_camera = { 0, 0, 0, 0 };

CameraSystem::CameraSystem()
{
	m_camera = SDL_Rect{ 0,0,0,0 };
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::Initialiser(int w, int h)
{
	m_camera.w = w;
	m_camera.h = h;
}

void CameraSystem::Update(jk::Entity * e)
{
	jk::Vector2f position = e->getComponent<TransformComponent>().position;

	if (position.x >= (m_camera.w / 2))
	{
		m_camera.x = position.x - m_camera.w;
	}
	else if (position.x < (m_camera.w / 2))
	{
		m_camera.x = 0;
	}
}

void CameraSystem::Reset()
{
	m_camera = SDL_Rect{ 0,0,0,0 };
}
