#include <iostream>
using namespace std;

void printSpiralMatrix(int mat[][5], int row, int column)
{
    int srow = 0, scol = 0, erow = row - 1, ecol = column - 1;
    while (srow <= erow && scol <= ecol)
    {
        for (int i = scol; i <= ecol; i++)
        {
            cout << mat[srow][i] << " ";
        }
        for (int j = srow + 1; j <= erow; j++)
        {
            cout << mat[j][ecol] << " ";
        }
        for (int i = ecol - 1; i >= scol; i--)
        {
            if (srow == erow)
            {
                break;
            }

            cout << mat[erow][i] << " ";
        }
        for (int j = erow - 1; j >= srow + 1; j--)
        {
            if (scol == ecol)
            {
                break;
            }

            cout << mat[j][scol] << " ";
        }
        scol++;
        ecol--;
        srow++;
        erow--;
    }
}

int main()
{
    int mat[6][5] = {{11, 22, 31, 41, 5},
                     {16, 17, 18, 19, 6},
                     {15, 24, 25, 20, 7},
                     {14, 23, 22, 21, 8},
                     {14, 23, 22, 21, 8},
                     {13, 12, 11, 10, 9}};

    printSpiralMatrix(mat, 6, 5);
    cout << endl;

    return 0;
}