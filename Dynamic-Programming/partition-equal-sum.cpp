#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool getAnswer(int n, int s, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (s == 0)
            return true;
        if (n == 0)
            return false;

        if (dp[n][s] != -1)
        {
            return dp[n][s];
        }
        else
        {
            if (nums[n - 1] <= s)
            {
                return dp[n][s] = getAnswer(n - 1, s - nums[n - 1], nums, dp) || getAnswer(n - 1, s, nums, dp);
            }
            else
            {
                return dp[n][s] = getAnswer(n - 1, s, nums, dp);
            }
        }
    }

    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        return getAnswer(nums.size(), target, nums, dp);
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, bool expected)
{
    Solution sol;
    bool result = sol.canPartition(nums);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 5, 11, 5}, true);

    // Example 2
    runTest({1, 2, 3, 5}, false);

    // Edge case: single element
    runTest({2}, false);

    // Edge case: two equal elements
    runTest({4, 4}, true);

    // Edge case: all same values
    runTest({3, 3, 3, 3}, true);

    // Edge case: large sum but impossible
    runTest({1, 1, 1, 1, 1, 1, 1, 1, 1, 10}, false);

    return 0;
}
