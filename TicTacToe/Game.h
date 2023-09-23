#pragma once

#include "GameAlogorithom.h"
#include "GameUI.h"

class Game
{
	Board board;
	BLOCK turn = BLOCK::O;
	GameUI ui;
public:
	void NewGame();

	void Run();

	bool GameEnd();
};