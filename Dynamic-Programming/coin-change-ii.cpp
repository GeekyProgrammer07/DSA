#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<long long>> dp(coins.size() + 1, vector<long long>(amount + 1));

        for (int i = 0; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= amount; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    // Include
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    // Exclude
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> dp;
//     int answer(int amount, int coinIdx, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         if (amount <= 0 || coinIdx == coins.size())
//         {
//             if (amount == 0)
//             {
//                 return 1;
//             }
//             return 0;
//         }

//         if (dp[amount][coinIdx] != -1)
//         {
//             return dp[amount][coinIdx];
//         }
//         else
//         {
//             int count = 0;
//             for (int i = coinIdx; i < coins.size(); i++)
//             {
//                 count += answer(amount - coins[i], i, coins, dp);
//             }

//             return dp[amount][coinIdx] = count;
//         }
//     }
//     int change(int amount, vector<int> &coins)
//     {
// //         vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
//         return answer(amount, 0, coins, dp);
//     }
// };

/* ---------- Test Runner ---------- */

void runTest(int amount, vector<int> coins, int expected)
{
    Solution sol;
    int result = sol.change(amount, coins);

    cout << "Amount: " << amount << endl;
    cout << "Coins: ";
    for (int c : coins)
        cout << c << " ";
    cout << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest(5, {1, 2, 5}, 4);

    // Example 2
    runTest(3, {2}, 0);

    // Example 3
    runTest(10, {10}, 1);

    // Edge case: amount = 0 (empty combination)
    runTest(0, {1, 2, 3}, 1);

    // Edge case: no coins
    runTest(5, {}, 0);

    // Edge case: multiple coins, single way
    runTest(4, {2}, 1);

    return 0;
}
