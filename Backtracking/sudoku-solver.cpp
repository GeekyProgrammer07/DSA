#include <bits/stdc++.h>
using namespace std;

void printSudoku(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int sudoku[][9], int row, int column, int digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == digit || sudoku[i][column] == digit)
        {
            return false;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (column / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (sudoku[i][j] == digit)
            {

                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int sudoku[][9], int row, int column)
{
    int nextRow = row;
    int nextColumn = column + 1;

    if (column + 1 == 9)
    {
        nextRow = row + 1;
        nextColumn = 0;
    }

    if (row == 9)
    {
        printSudoku(sudoku);
        return true;
    }

    if (sudoku[row][column] != 0)
    {
        return solveSudoku(sudoku, nextRow, nextColumn);
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if (isSafe(sudoku, row, column, digit))
        {
            sudoku[row][column] = digit;
            if (solveSudoku(sudoku, nextRow, nextColumn))
            {
                return true;
            }
        }
        sudoku[row][column] = 0;
    }

    return false;
}

int main()
{
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Initial Sudoku Grid:" << endl;
    printSudoku(sudoku);
    cout << "After Solving Sudoku:" << endl;
    solveSudoku(sudoku, 0, 0);
    return 0;
}