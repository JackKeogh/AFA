#include "CameraSystem.h"

SDL_Rect CameraSystem::m_camera = SDL_Rect{ 0,0,0,0 };
int CameraSystem::m_endpoint = 0;

CameraSystem::CameraSystem()
{

}

CameraSystem::~CameraSystem()
{
}

bool CameraSystem::Initialiser(int w, int h)
{
	m_camera.w = w;
	m_camera.h = h;

	return true;
}

void CameraSystem::Update(float px)
{
	if (px + (m_camera.w / 2) > m_endpoint)
	{
		m_camera.x = m_endpoint - m_camera.w;
	}
	else if (px >= (m_camera.w / 2))
	{
		m_camera.x = px - (m_camera.w / 2);
	}
	else if (px < (m_camera.w / 2))
	{
		m_camera.x = 0;
	}
}

void CameraSystem::Reset()
{
	m_camera = SDL_Rect{ 0,0,0,0 };
}

void CameraSystem::setEndPoint(int value)
{
	m_endpoint = value;
}
