#include <iostream>
using namespace std;

//O(n)
int diagonalSum(int mat[][5], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
        if (i != n - i - 1)
        {
            sum += mat[i][n - i - 1];
        }
    }
    return sum;
}

// O(n^2)
//  int diagonalSum(int mat[][5], int n)
//  {
//      int sum = 0;
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = 0; j < n; j++)
//          {
//              if (i == j)
//              {
//                  sum += mat[i][j];
//              }
//              else if (j == n - i - 1)
//              {
//                  sum += mat[i][j];
//              }
//          }
//      }
//      return sum;
//  }

int main()
{
    int mat[6][5] = {{1, 22, 31, 5},
                     {16, 2, 6, 7},
                     {15, 7, 3, 20},
                     {8, 8, 22, 4}};

    cout << diagonalSum(mat, 4);
    cout << endl;

    return 0;
}