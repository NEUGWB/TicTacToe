#include "GameUI.h"

void GameUI::OnNewGame(Board& board)
{
	printf("游戏开始\n");
}

void GameUI::OnPlayerMove(Board& board, int i, int j)
{
	printf("你下在了%d行%d列，当前局面是\n", i + 1, j + 1);
	PrintBoard(board);
}

void GameUI::OnAIMove(Board& board, int i, int j)
{
	printf("***电脑下在了%d行%d列***\n", i + 1, j + 1);
	PrintBoard(board);
}

void GameUI::OnGameEnd(STATE state)
{
	if (state == STATE::O_WIN) {
		printf("你赢了\n");
	}
	else if (state == STATE::X_WIN) {
		printf("你输了\n");
	}
	else if (state == STATE::DRAW) {
		printf("平局\n");
	}
}

void GameUI::PlayerMoveHint()
{
	printf("该你下了，请输入坐标，例如1 2表示第一行第二列\n");
}

void GameUI::InvalidMoveHint()
{
	printf("不可以下在这里\n");
}

void GameUI::PrintBoard(Board& board)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			auto b = board(i, j);
			if (b == BLOCK::N)
			{
				printf("_");
			}
			else if (b == BLOCK::O) {
				printf("O");
			}
			else if (b == BLOCK::X) {
				printf("X");
			}
		}
		printf("\n");
	}
	printf("\n");
}
