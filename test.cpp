#include <iostream>
#include "game.h"

using namespace std;

bool Test::testHorizontalWin()
{
    Board board;
    Player player1(board, 'R');
    Player player2(board, 'B');

    board.playColumn(player1, 0);
    board.playColumn(player2, 0);
    board.playColumn(player1, 1);
    board.playColumn(player2, 1);
    board.playColumn(player1, 2);
    board.playColumn(player2, 2);
    board.playColumn(player1, 3);

    board.displayBoard();

    return board.checkWin(player1.piece);
}

bool Test::testVerticalWin()
{
    Board board;
    Player player1(board, 'R');
    Player player2(board, 'B');

    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 0);

    board.displayBoard();

    return board.checkWin(player1.piece);
}

bool Test::testDiagonalLWin()
{
    Board board;
    Player player1(board, 'R');
    Player player2(board, 'B');

    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 1);
    board.playColumn(player2, 2);
    board.playColumn(player1, 2);
    board.playColumn(player2, 3);
    board.playColumn(player1, 2);
    board.playColumn(player2, 3);
    board.playColumn(player1, 3);
    board.playColumn(player2, 4);
    board.playColumn(player1, 3);

    board.displayBoard();

    return board.checkWin(player1.piece);
}

bool Test::testDiagonalRWin()
{
    Board board;
    Player player1(board, 'R');
    Player player2(board, 'B');

    board.playColumn(player1, 0);
    board.playColumn(player2, 0);
    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 0);
    board.playColumn(player2, 1);
    board.playColumn(player1, 1);
    board.playColumn(player2, 2);
    board.playColumn(player1, 2);
    board.playColumn(player2, 4);
    board.playColumn(player1, 3);

    board.displayBoard();

    return board.checkWin(player1.piece);
}