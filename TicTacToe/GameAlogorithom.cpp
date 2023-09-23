#include "GameAlogorithom.h"
#include <vector>

std::tuple<int, int, int> GameAlogorithom::GetScore(Board& board, BLOCK turn)
{
	auto state = GetState(board);
	if (state != STATE::MOVING)
	{
		std::tuple<int, int, int> ret = std::make_tuple(-1, -1, static_cast<int>(state));
		return ret;
	}

	std::vector<std::tuple<int, int, int> > vec;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board(i, j) == BLOCK::N)
			{
				board(i, j) = turn;
				auto ret = GetScore(board, turn == BLOCK::O ? BLOCK::X : BLOCK::O);
				board(i, j) = BLOCK::N;
				vec.emplace_back(i, j, std::get<2>(ret));
			}
		}
	}
	
	if (turn == BLOCK::O)
	{
		int m = 9999, mi = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			auto v = vec[i];
			if (std::get<2>(v) < m)
			{
				m = std::get<2>(v);
				mi = i;
			}
		}
		return vec[mi];
	}
	if (turn == BLOCK::X)
	{
		int m = -9999, mi = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			auto v = vec[i];
			if (std::get<2>(v) > m)
			{
				m = std::get<2>(v);
				mi = i;
			}
		}
		return vec[mi];
	}
}

#define STATE_PARSE(x, y) if (board(x, y)==BLOCK::O) return STATE::O_WIN; \
else if (board(x, y)==BLOCK::X) return STATE::X_WIN;

STATE GameAlogorithom::GetState(Board& board)
{
	if (board(0, 0) == board(0, 1) && board(0, 1) == board(0, 2)
		|| board(0, 0) == board(1, 0) && board(1, 0) == board(2, 0))
	{
		STATE_PARSE(0, 0)
	}
	if (board(2, 0) == board(2, 1) && board(2, 1) == board(2, 2)
		|| board(0, 2) == board(1, 2) && board(1, 2) == board(2, 2))
	{
		STATE_PARSE(2, 2)
	}
	if (board(1, 1) == board(0, 1) && board(1, 1) == board(2, 1)
		|| board(1, 1) == board(1, 0) && board(1, 1) == board(1, 2)
		|| board(1, 1) == board(0, 0) && board(1, 1) == board(2, 2)
		|| board(1, 1) == board(0, 2) && board(1, 1) == board(2, 0))
	{
		STATE_PARSE(1, 1)
	}
	if (board.Full())
	{
		return STATE::DRAW;
	}
	return STATE::MOVING;
}
