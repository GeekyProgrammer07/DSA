#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "--------------------------" << endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    int n = board.size();

    // Check column above
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

int nqueen(vector<vector<char>> &board, int row)
{
    int n = board.size(), count = 0;
    if (row == n)
    {
        printBoard(board, n);
        return 1;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            count += nqueen(board, row + 1);
            board[row][col] = '.';
        }
    }
    return count; //No of possible solution at each level
}

int main()
{
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    cout << nqueen(board, 0) << endl;
    return 0;
}
