#include <vector>

#pragma once

#ifndef GAME
#define GAME

using namespace std;

class Player;
class Test;
class Board;
class Game;

const int ROWS = 6;
const int COLUMNS = 7;

// Enable to show direction win was calculated from
const bool DEBUG = false;
// Enable to run tests on winning directions
const bool RUN_TESTS = false;

class Test
{
public:
	bool testHorizontalWin();
	bool testVerticalWin();
	bool testDiagonalLWin();
	bool testDiagonalRWin();
};

class Game
{
public:
	void playGame();
	void runTests();
};

class Board
{
public:
	Board();
	void displayBoard();
	bool playColumn(Player &player, int column);
	bool checkWin(char piece);
	bool boardFull();

private:
	char grid[ROWS][COLUMNS];
};

class Player
{
public:
	Player(Board &board, char piece);
	bool playColumn(int column);
	char piece;

private:
	Board &board;
};

#endif