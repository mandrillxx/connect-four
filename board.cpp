#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

Board::Board()
{
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			this->grid[x][y] = ' ';
		}
	}
}

void Board::displayBoard()
{
	cout << "|";
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << " [" << i + 1 << "] |";
	}
	cout << endl;

	cout << "|";
	for (int i = 0; i < COLUMNS * 5.8; i++)
	{
		cout << "-";
	}
	cout << "|" << endl;
	for (int x = 0; x < ROWS; x++)
	{
		cout << "|";
		for (int y = 0; y < COLUMNS; y++)
		{
			cout << " (" << grid[x][y] << ") |";
		}
		cout << endl;
	}
	cout << "|";
	for (int i = 0; i < COLUMNS * 5.8; i++)
	{
		cout << "-";
	}
	cout << "|" << endl;
}

bool Board::boardFull()
{
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			if (this->grid[x][y] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::playColumn(Player &player, int column)
{
	for (int i = ROWS - 1; i >= 0; i--)
	{
		if (this->grid[i][column] == ' ')
		{
			this->grid[i][column] = player.piece;
			return true; // Piece was put down
		}
	}
	return false; // Column is full
}

bool Board::checkWin(char piece)
{
	// Check for horizontal wins
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col <= COLUMNS - 4; col++)
		{
			if (this->grid[row][col] == piece && this->grid[row][col + 1] == piece && this->grid[row][col + 2] == piece && this->grid[row][col + 3] == piece)
			{
				if (DEBUG)
				{
					cout << "Horizontal win" << endl;
				}
				return true;
			}
		}
	}

	// Check for vertical wins
	for (int col = 0; col < COLUMNS; col++)
	{
		for (int row = 0; row <= ROWS; row++)
		{
			if (this->grid[row][col] == piece && this->grid[row + 1][col] == piece && this->grid[row + 2][col] == piece && this->grid[row + 3][col] == piece)
			{
				if (DEBUG)
				{
					cout << "Vertical win" << endl;
				}
				return true;
			}
		}
	}

	// Check for diagonal wins, down right
	for (int row = 0; row <= ROWS - 4; row++)
	{
		for (int col = 0; col <= COLUMNS - 4; col++)
		{
			if (this->grid[row][col] == piece && this->grid[row + 1][col + 1] == piece && this->grid[row + 2][col + 2] == piece && this->grid[row + 3][col + 3] == piece)
			{
				if (DEBUG)
				{
					cout << "Diagonal (DR) win" << endl;
				}
				return true;
			}
		}
	}

	// Check for diagonal wins, up right
	for (int row = 3; row < ROWS; row++)
	{
		for (int col = 0; col <= COLUMNS - 4; col++)
		{
			if (this->grid[row][col] == piece && this->grid[row - 1][col + 1] == piece && this->grid[row - 2][col + 2] == piece && this->grid[row - 3][col + 3] == piece)
			{
				if (DEBUG)
				{
					cout << "Diagonal (UR) win" << endl;
				}
				return true;
			}
		}
	}

	return false;
}
