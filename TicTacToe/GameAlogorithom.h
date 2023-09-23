#pragma once
#include <utility>
#include <tuple>

enum class BLOCK
{
	N = 0,
	O,
	X,
};

enum class STATE
{
	O_WIN = -1,
	DRAW = 0,
	X_WIN = 1,
	MOVING,
};

class Board
{
	BLOCK block[9];
public:
	Board()
	{
		for (int i = 0; i < 9; ++i)
		{
			block[i] = BLOCK::N;
		}
	}

	BLOCK& operator()(int x, int y)
	{
		return block[y + x * 3];
	}

	void Move(int x, int y, BLOCK b)
	{
		block[y + x * 3] = b;
	}

	bool Full()
	{
		for (auto b : block)
		{
			if (b == BLOCK::N)
			{
				return false;
			}
		}
		return true;
	}
};


class GameAlogorithom
{
public:
	static std::tuple<int, int, int> GetScore(Board& board, BLOCK turn);

	static STATE GetState(Board& board);
};
