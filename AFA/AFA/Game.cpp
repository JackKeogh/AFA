#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Initialiser()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	return true;
}

void Game::Run()
{

}

void Game::Clean()
{
	SDL_Quit();
}