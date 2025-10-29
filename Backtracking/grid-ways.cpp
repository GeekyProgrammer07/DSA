#include <bits/stdc++.h>
using namespace std;

int answer(int row, int column, int n, int m, vector<vector<char>> mat, string ways)
{
    int count = 0;
    if (row == n-1 && column == m-1)
    {
        cout << ways << endl;
        return 1;
    }

    if (row > n-1 || column > m -1)
    {
        return 0;
    }
    
    count += answer(row + 1, column, n, m, mat, ways + "D") + answer(row, column + 1, n, m, mat, ways + "R");
    return count;
}

int main()
{
    string ways = "";
    vector<vector<char>> matrix(3,vector<char>(3,'.'));
    cout << answer(0,0,3,3,matrix, ways) << endl;
    return 0;
}