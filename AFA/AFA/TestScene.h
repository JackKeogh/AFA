#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene() 
	{
		RenderSystem::RenderColor(SDL_Color{ 0, 0, 0, 255 });
	};
	~TestScene() {};

	void Update() override {};
	void Render() override
	{
		RenderSystem::Clear();

		RenderSystem::Present();
	};
	void Event() override {};
	bool Running() override { return m_running; };
	void Initialise() override {};
	void LoadLevel() override {};

private:

};