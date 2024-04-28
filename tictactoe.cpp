#include <iostream>
using namespace std;
void printBoard(char board[][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "---------" << endl;
    }
}
bool checkWinner(char board[][3], char player) 
{
    for (int i = 0; i < 3; ++i) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
bool isBoardFull(char board[][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
bool makeMove(char board[][3], char player, int row, int col) 
{
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        return false;
    board[row][col] = player;
    return true;
}
int main() 
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1, player2;
    char currentPlayer;
    if (rand() % 2 == 0) 
    {
        player1 = 'X';
        player2 = 'O';
        currentPlayer = player1;
    } 
    else 
    {
        player1 = 'O';
        player2 = 'X';
        currentPlayer = player2;
    }
    cout << "Player 1 is: " << player1 << endl;
    cout << "Player 2 is: " << player2 << endl;
    while (true) 
    {
        printBoard(board);
        int row, col;
        cout << "Player " << (currentPlayer == player1 ? "1" : "2") << ", enter row (0, 1, or 2): ";
        cin >> row;
        cout << "Player " << (currentPlayer == player1 ? "1" : "2") << ", enter column (0, 1, or 2): ";
        cin >> col;
	if (!makeMove(board, currentPlayer, row, col)) 
	{
            cout << "Invalid move, try again." << endl;
            continue;
        }
        if (checkWinner(board, currentPlayer)) 
        {
            printBoard(board);
            cout << "Player " << (currentPlayer == player1 ? "1" : "2") << " wins!" << endl;
            break;
        } else if (isBoardFull(board)) 
        {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    return 0;
}

