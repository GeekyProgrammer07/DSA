#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // Transpose the matrix
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            // int start = *(matrix[i].data()), end = *(matrix[i].data() + (matrix[i].size() - 1));
            int start = 0, end = matrix[0].size() - 1;
            while (start < end)
            {
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};

// Utility function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;
}

int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    sol.rotate(matrix1);
    printMatrix(matrix1);

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    sol.rotate(matrix2);
    printMatrix(matrix2);

    // Test Case 3 (edge case: 1x1 matrix)
    vector<vector<int>> matrix3 = {
        {42}};
    sol.rotate(matrix3);
    printMatrix(matrix3);

    return 0;
}
