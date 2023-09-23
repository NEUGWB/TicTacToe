// TicTacToe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "GameAlogorithom.h"
#include "Game.h"
#include <iostream>

int main()
{
    Game game;
    game.NewGame();
    while (true) {
        game.Run();
        if (game.GameEnd()) {
            break;
        }
    }
    return 0;
}
