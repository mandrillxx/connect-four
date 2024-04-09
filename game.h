#include <vector>

#pragma once

#ifndef GAME
#define GAME

using namespace std;

class Player;
class Board;

const int ROWS = 6;
const int COLUMNS = 7;

// Enable to show direction win was calculated from
const bool DEBUG = false;

namespace Game
{
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
}
