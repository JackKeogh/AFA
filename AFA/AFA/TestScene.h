#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene() {};
	~TestScene() {};

	void Update() override {};
	void Render() override {};
	void Event() override {};
	bool Running() override { return m_running; };
	void Initialise() override {};
	void LoadLevel() override {};

private:

};