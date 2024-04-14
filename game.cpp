#include <iostream>
#include "./game.h"

using namespace std;

void Game::playGame()
{
    // Initialize board & player classes
    Board board;
    Player player1(board, 'R');
    Player player2(board, 'B');

    board.displayBoard();

    char going = player1.piece;
    while (true)
    {
        if (board.checkWin(player1.piece))
        {
            cout << "CONGRATULATIONS!! " << player1.piece << " WINS!!" << endl;
            return;
        }
        else if (board.checkWin(player2.piece))
        {
            cout << "CONGRATULATIONS!! " << player2.piece << " WINS!!" << endl;
            return;
        }

        if (board.boardFull())
        {
            cout << "The board is full. The game is a draw." << endl;
            return;
        }

        cout << (going == player1.piece ? "Player 1" : "Player 2") << " (" << going << ") Select column [1-" << COLUMNS << "], 'q' to quit: ";
        char input;
        cin >> input;
        if (input == 'q')
        {
            return;
        }
        if (!isdigit(input))
        {
            cout << "Invalid column entered." << endl;
            continue;
        }
        // Input is a number, cast input to an int
        int column = input - '0';

        if (column > COLUMNS || column <= 0)
        {
            cout << "Invalid column entered." << endl;
            continue;
        }

        // Attempt to play column
        Player &goingPlayer = going == player1.piece ? player1 : player2;
        bool success = board.playColumn(goingPlayer, column - 1);
        if (!success)
        {
            cout << "Sorry that column is full. Try again." << endl;
            continue;
        }
        cout << endl;
        board.displayBoard();

        // Alternate turns
        going = going == player1.piece ? player2.piece : player1.piece;
    }
}

void Game::runTests()
{
    Test test;
    bool horizontalSuccess = test.testHorizontalWin();
    bool verticalSuccess = test.testVerticalWin();
    bool leftDiagonalSuccess = test.testDiagonalLWin();
    bool rightDiagonalSuccess = test.testDiagonalRWin();

    cout << "Horizontal Win Test: " << (horizontalSuccess ? "PASSED" : "FAILED") << endl;
    cout << "Vertical Win Test: " << (verticalSuccess ? "PASSED" : "FAILED") << endl;
    cout << "Left Diagonal Win Test: " << (leftDiagonalSuccess ? "PASSED" : "FAILED") << endl;
    cout << "Right Diagonal Win Test: " << (rightDiagonalSuccess ? "PASSED" : "FAILED") << endl;
}