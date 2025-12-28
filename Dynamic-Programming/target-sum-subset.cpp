#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    bool getAnswer(int n, int sum, vector<int> &arr)
    {
        if (n == 0 || sum == 0)
        {
            if (sum == 0)
            {
                return true;
            }
            return false;
        }
        if (dp.empty())
        {
            dp.assign(n + 1, vector<int>(sum + 1, -1));
        }
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        else
        {
            if (arr[n - 1] <= sum)
            {
                bool incl = getAnswer(n - 1, sum - arr[n - 1], arr);
                bool excl = getAnswer(n - 1, sum, arr);

                return dp[n][sum] = incl || excl;
            }
            else
            {
                return dp[n][sum] = getAnswer(n - 1, sum, arr);
            }
        }
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        return getAnswer(arr.size(), sum, arr);
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> arr, int sum, bool expected)
{
    Solution sol;
    bool result = sol.isSubsetSum(arr, sum);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "| Sum = " << sum << endl;

    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({3, 34, 4, 12, 5, 2}, 9, true);

    // Example 2
    runTest({3, 34, 4, 12, 5, 2}, 30, false);

    // Example 3
    runTest({1, 2, 3}, 6, true);

    // Edge case: sum = 0 (empty subset)
    runTest({5, 10, 12}, 0, true);

    // Edge case: single element equal to sum
    runTest({7}, 7, true);

    // Edge case: single element not equal to sum
    runTest({7}, 3, false);

    return 0;
}
