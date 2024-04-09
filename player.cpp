#include "game.h"

bool Player::playColumn(int column)
{
	return this->board.playColumn(*this, column);
}

Player::Player(Board &board, char piece) : board(board), piece(piece)
{
	// Initialize player and set internal state variables
}