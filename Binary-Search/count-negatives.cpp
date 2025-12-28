#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int i = 0, j = grid[0].size() - 1, n = grid.size();
        int answer = 0;
        while (i < n && j >= 0)
        {
            if (grid[i][j] < 0)
            {
                answer += n - i;
                j--;
            }
            else
            {
                i++;
            }
        }

        return answer;
    }
};

/* ---------- Utility Functions ---------- */

void runTest(vector<vector<int>> grid, int expected)
{
    Solution sol;
    int result = sol.countNegatives(grid);

    cout << "Grid:" << endl;
    for (auto &row : grid)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest(
        {{4, 3, 2, -1},
         {3, 2, 1, -1},
         {1, 1, -1, -2},
         {-1, -1, -2, -3}},
        8);

    // Example 2
    runTest(
        {{3, 2},
         {1, 0}},
        0);

    // Edge case: all negative
    runTest(
        {{-1, -2},
         {-3, -4}},
        4);

    // Edge case: single row
    runTest(
        {{5, 4, 3, -1, -2}},
        2);

    // Edge case: single column
    runTest(
        {{3},
         {2},
         {-1},
         {-5}},
        2);

    return 0;
}
