#include "Game.h"
#include <cassert>

void Game::NewGame()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board.Move(i, j, BLOCK::N);
		}
	}
	ui.OnNewGame(board);
}

void Game::Run()
{
	if (turn == BLOCK::O) {
		ui.PlayerMoveHint();
		int i, j;
		std::cin >> i >> j;
		--i;
		--j;
		if (board(i, j) != BLOCK::N) {
			ui.InvalidMoveHint();
			return;
		}
		board.Move(i, j, BLOCK::O);
		ui.OnPlayerMove(board, i, j);
		turn = BLOCK::X;
	}
	else if (turn == BLOCK::X) {
		auto score = GameAlogorithom::GetScore(board, BLOCK::X);
		int i = std::get<0>(score);
		int j = std::get<1>(score);
		board.Move(i, j, BLOCK::X);
		ui.OnAIMove(board, i, j);
		turn = BLOCK::O;
	}
}

bool Game::GameEnd()
{
	auto state = GameAlogorithom::GetState(board);
	if (state != STATE::MOVING) {
		ui.OnGameEnd(state);
		return true;
	}
	return false;
}