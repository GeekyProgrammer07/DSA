#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if ((m * n) != original.size())
        {
            return {};
        }

        vector<vector<int>> solutionArray(m, vector<int>(n));
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                solutionArray[i][j] = original[index];
                index++;
            }
        }
        return solutionArray;
    }
};

// Utility function to print 2D vector
void printMatrix(const vector<vector<int>> &matrix)
{
    if (matrix.empty())
    {
        cout << "[]" << endl;
        return;
    }
    for (auto &row : matrix)
    {
        cout << "[";
        for (int j = 0; j < row.size(); j++)
        {
            cout << row[j];
            if (j < row.size() - 1)
                cout << ",";
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> original1 = {1, 2, 3, 4};
    int m1 = 2, n1 = 2;
    auto result1 = sol.construct2DArray(original1, m1, n1);
    printMatrix(result1); // Expected: [[1,2],[3,4]]

    // Test Case 2
    vector<int> original2 = {1, 2, 3};
    int m2 = 1, n2 = 3;
    auto result2 = sol.construct2DArray(original2, m2, n2);
    printMatrix(result2); // Expected: [[1,2,3]]

    // Test Case 3
    vector<int> original3 = {1, 2};
    int m3 = 1, n3 = 1;
    auto result3 = sol.construct2DArray(original3, m3, n3);
    printMatrix(result3); // Expected: []

    return 0;
}
