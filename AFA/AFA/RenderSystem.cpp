#include "RenderSystem.h"

SDL_Renderer * RenderSystem::m_renderer = 0;
SDL_Window * RenderSystem::m_window = 0;

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{

}

bool RenderSystem::Init(string title, int x, int y, int w, int h)
{
	if (x == 0 && y == 0)
	{
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
	}
	else
	{
		m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, NULL);
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, NULL);

	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

	if (m_renderer == nullptr)
		return false;

	if (CameraSystem::Initialiser(w, h))
		return true;
	else
		return false;
}

SDL_Renderer * RenderSystem::Renderer()
{
	return m_renderer;
}

void RenderSystem::RenderColor(SDL_Color Color)
{
	SDL_SetRenderDrawColor(m_renderer, Color.r, Color.g, Color.b, Color.a);
}

void RenderSystem::Clear()
{
	SDL_RenderClear(m_renderer);
}

void RenderSystem::Draw(SDL_Texture * Texture, SDL_Rect DstRect)
{
	SDL_RenderCopy(m_renderer, Texture, NULL, &DstRect);
}

void RenderSystem::Draw(SDL_Rect DstRect)
{
	RenderColor(SDL_Color{ 255, 0, 255, 255 });

	DstRect.x -= CameraSystem::Camera().x;

	SDL_RenderDrawRect(m_renderer, &DstRect);
}

void RenderSystem::Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect)
{
	SDL_RenderCopy(m_renderer, Texture, &SrcRect, &DstRect);
}

void RenderSystem::Draw(Box * box)
{
	RenderColor(box->color);
	SDL_RenderFillRect(m_renderer, &box->rect);
}

void RenderSystem::Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect, float Rotation)
{
	DstRect.x -= CameraSystem::Camera().x;

	SDL_RenderCopyEx(m_renderer, Texture, &SrcRect, &DstRect, Rotation, NULL, SDL_FLIP_NONE);
}

void RenderSystem::Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect, float Rotation, SDL_Point Origin)
{
	SDL_RenderCopyEx(m_renderer, Texture, &SrcRect, &DstRect, Rotation, &Origin, SDL_FLIP_NONE);
}

void RenderSystem::Present()
{
	RenderColor(SDL_Color{ 0, 0, 0, 255 });
	SDL_RenderPresent(m_renderer);
}