#include "game.h"

bool Game::Player::playColumn(int column)
{
	return this->board.playColumn(*this, column);
}

Game::Player::Player(Board &board, char piece) : board(board), piece(piece)
{
	// Initialize player and set internal state variables
}