#include <bits/stdc++.h>
using namespace std;

void findPath(int maze[][4], int row, int col, int n, string path)
{
    if (row >= n || col >= n || maze[row][col] == 1)
        return;

    if (row == n - 1 && col == n - 1)
    {
        cout << path << endl;
        return;
    }

    // Move Down
    findPath(maze, row + 1, col, n, path + "D");
    // Move Right
    findPath(maze, row, col + 1, n, path + "R");
}

int main()
{
    int maze[4][4] = {
        {0, 1, 1, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 0}};

    cout << "All possible paths through the maze:" << endl;
    findPath(maze, 0, 0, 4, "");
    return 0;
}
