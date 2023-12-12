#include <iostream>
using namespace std;

class TicTacToeGame 
{
private:
    char board[3][3];
    int row, column;
    char turn;
    bool draw;

public:
    TicTacToeGame() : turn('X'), draw(true) 
	{
        initializeBoard();
    }

    void initializeBoard() 
	{
        char num = '1';
        for (int i = 0; i < 3; ++i) 
		{
            for (int j = 0; j < 3; ++j) 
			{
                board[i][j] = num++;
            }
        }
    }

    void display_board() 
	{
        cout << "  PLAYER - 1 [X] \n  PLAYER - 2 [O]\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
        cout << "\t\t     |     |     \n";
    }

    void playerTurn() 
	{
        int ch;
        cout << (turn == 'X' ? " Player - 1 [X] turn : \n " : " Player - 2 [O] turn : \n ");
        cin >> ch;

        switch (ch) 
		{
            case 1: row = 0; column = 0; 
					break;
            case 2: row = 0; column = 1; 
					break;
            case 3: row = 0; column = 2; 
					break;
            case 4: row = 1; column = 0; 
					break;
            case 5: row = 1; column = 1; 
					break;
            case 6: row = 1; column = 2; 
					break;
            case 7: row = 2; column = 0; 
					break;
            case 8: row = 2; column = 1; 
					break;
            case 9: row = 2; column = 2; 
					break;
            default:
                cout << "Invalid Move";
        }

        if (board[row][column] != 'X' && board[row][column] != 'O') 
		{
            board[row][column] = turn;
            togglePlayer();
        } else 
		{
            cout << " Box already filled! \n  Please choose another!!\n\n";
            playerTurn();
        }
    }

    void togglePlayer() 
	{
        turn = (turn == 'X') ? 'O' : 'X';
    }

    bool checkWinner(char symbol) 
	{
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) 
		{
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true; // Check rows
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true; // Check columns
        }
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true; // Check diagonal 1
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true; // Check diagonal 2

        return false;
    }

    bool isBoardFull() 
	{
        // Check if the board is full
        for (int i = 0; i < 3; ++i) 
		{
            for (int j = 0; j < 3; ++j) 
			{
                if (board[i][j] != 'X' && board[i][j] != 'O') 
				{
                    return false; // There's an empty space
                }
            }
        }
        return true; // Board is full
    }

    bool gameOver() 
	{
        if (checkWinner('X')) 
		{
            cout << "\n\n  Congratulations! Player with 'X' has won the game\n";
            return false;
        } 
		else if (checkWinner('O')) 
		{
            cout << "\n\n  Congratulations! Player with 'O' has won the game\n";
            return false;
        } 
		else if (isBoardFull()) 
		{
            cout << "\n\n  GAME DRAW!!! \n\n";
            return false;
        }
        return true;
    }
};

int main() 
{
    TicTacToeGame game;
    cout << "\t\t\t T I C  -- T A C -- T O E -- G A M E \t\t\t";
    cout << "\n\t\t\t  FOR 2 PLAYERS  \n\t\t";

    while (game.gameOver()) 
	{        
        game.display_board();
        game.playerTurn();
    }

    return 0;
}

