#include "GameUI.h"

void GameUI::OnNewGame(Board& board)
{
	printf("��Ϸ��ʼ\n");
}

void GameUI::OnPlayerMove(Board& board, int i, int j)
{
	printf("��������%d��%d�У���ǰ������\n", i + 1, j + 1);
	PrintBoard(board);
}

void GameUI::OnAIMove(Board& board, int i, int j)
{
	printf("***����������%d��%d��***\n", i + 1, j + 1);
	PrintBoard(board);
}

void GameUI::OnGameEnd(STATE state)
{
	if (state == STATE::O_WIN) {
		printf("��Ӯ��\n");
	}
	else if (state == STATE::X_WIN) {
		printf("������\n");
	}
	else if (state == STATE::DRAW) {
		printf("ƽ��\n");
	}
}

void GameUI::PlayerMoveHint()
{
	printf("�������ˣ����������꣬����1 2��ʾ��һ�еڶ���\n");
}

void GameUI::InvalidMoveHint()
{
	printf("��������������\n");
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
