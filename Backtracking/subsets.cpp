#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> answer;
    void solve(vector<int> &nums, int i, vector<int> temp)
    {
        if (i == nums.size())
        {
            answer.push_back(temp);
            return;
        }
        // Selecting the option
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        temp.pop_back();
        solve(nums, i + 1, temp);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        solve(nums, 0, temp);
        return answer;
    }
};

/* ---------- Utility Functions ---------- */

void printResult(const vector<vector<int>> &result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < result[i].size())
                cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size())
            cout << ",";
    }
    cout << "]" << endl;
}

void runTest(vector<int> nums)
{
    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: ";
    printResult(result);

    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest({1, 2, 3});

    // Example 2
    runTest({0});

    // Edge case: two elements
    runTest({5, 10});

    // Edge case: maximum size
    runTest({-1, 0, 1, 2, 3});

    return 0;
}
