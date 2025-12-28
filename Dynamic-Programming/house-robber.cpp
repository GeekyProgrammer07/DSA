#include <bits/stdc++.h>
using namespace std;
// TODO: Not Completed

// O(1) => Space Complexity
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prevRobbed = 0;
        int prevNotRobbed = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int currRobbed = prevNotRobbed + nums[i];
            int currNotRobbed = max(prevRobbed, prevNotRobbed);

            prevRobbed = currRobbed;
            prevNotRobbed = currNotRobbed;
        }

        return max(prevRobbed, prevNotRobbed);
    }
};

// Tabularization
// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//         // Base case
//         dp[0][0] = 0;
//         dp[0][1] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             dp[i][0] = dp[i - 1][1] + nums[i - 1];
//             dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
//         }
//         return max(dp[n][0], dp[n][1]);
//     }
// };

// Memoization
//  class Solution
//  {
//  public:
//      vector<vector<int>> dp;
//      int robbed(int housesLeft, int prev, vector<int> &nums)
//      {
//          if (housesLeft == 0)
//          {
//              return 0;
//          }
//          if (dp.empty())
//          {
//              // int sumArray = accumulate(nums.begin(), nums.end(), 0);
//              dp.assign(housesLeft + 1, vector<int>(3, -1));
//          }
//          if (dp[housesLeft][prev] != -1)
//          {
//              return dp[housesLeft][prev];
//          }
//          else
//          {
//              // 0 means robbed 1 means not robbed
//              if (prev != 0)
//              {
//                  int incl = robbed(housesLeft - 1, 0, nums) + nums[housesLeft - 1];
//                  int excl = robbed(housesLeft - 1, 1, nums);

//                 return dp[housesLeft][prev] = max(incl, excl);
//             }
//             else
//             {
//                 return dp[housesLeft][prev] = robbed(housesLeft - 1, 1, nums);
//             }
//         }
//     }

//     int rob(vector<int> &nums)
//     {
// //         return robbed(nums.size(), 1, nums);
//     }
// };

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.rob(nums);

    cout << "Houses: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 2, 3, 1}, 4);

    // Example 2
    runTest({2, 7, 9, 3, 1}, 12);

    // Edge case: single house
    runTest({5}, 5);

    // Edge case: two houses
    runTest({2, 1}, 2);

    // Edge case: all zeros
    runTest({0, 0, 0, 0}, 0);

    // Edge case: increasing values
    runTest({1, 2, 3, 4, 5}, 9);

    return 0;
}
