/// <summary>
/// Awnie's Frosty Adventure game.
/// </summary>
/// <start date>
/// 11/10/2018
/// </start date>
/// <end date>
/// 
/// </end date>
/// <authors>
/// Jack Keogh
/// Jason Hannon
/// </authors>

#pragma once
#include "stdafx.h"
#include "Game.h"

int main(int argc, char * argv[])
{
	Game * game = new Game;

	if (game->Initialiser())
	{
#if _DEBUG
		cout << "The game was successfully created..." << endl;
#endif
		game->Run();
	}
	else
	{
#if _DEBUG
		cout << "Failed to create game, exiting..." << endl;
#endif
	}

	game->Clean();

	return 0;
}