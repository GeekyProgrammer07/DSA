#include <iostream>
using namespace std;

int main()
{
    int row, column;
    cin >> row >> column;

    int **mat = new int *[row];

    for (int i = 0; i < 5; i++)
    {
        mat[i] = new int[column];
    }
    int num = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            mat[i][j] = num++;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}