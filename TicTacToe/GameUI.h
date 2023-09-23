#pragma once
#include "GameAlogorithom.h"
#include <iostream>
class GameUI
{
public:
	void OnNewGame(Board& board);

	void OnPlayerMove(Board& board, int i, int j);

	void OnAIMove(Board& board, int i, int j);

	void OnGameEnd(STATE state);

	void PlayerMoveHint();

	void InvalidMoveHint();

	void PrintBoard(Board &board);
};