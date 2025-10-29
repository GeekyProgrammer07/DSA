#include <iostream>
using namespace std;

bool searchMat(int mat[][5], int row, int col, int key)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int mat[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    cout << (searchMat(mat, 5, 5, 14) ? "true" : "false") << endl;
    cout << (searchMat(mat, 5, 5, 100) ? "true" : "false") << endl;
    return 0;
}