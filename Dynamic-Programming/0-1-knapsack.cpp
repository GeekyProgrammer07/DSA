#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
//  int knapsackRec(int weightKnapsack, int n, vector<int> val, vector<int> wt)
//  {
//      if (n == 0 || weightKnapsack == 0)
//      {
//          return 0;
//      }
//      if (wt[n - 1] <= weightKnapsack)
//      {
//          int incl = knapsackRec(weightKnapsack - wt[n - 1], n - 1, val, wt) + val[n - 1];
//          int excl = knapsackRec(weightKnapsack, n - 1, val, wt);

//         return max(incl, excl);
//     }
//     else
//     {
//         return knapsackRec(weightKnapsack, n - 1, val, wt);
//     }
// }

// vector<vector<int>> dp; // dp[n][w]
// Memoization solution
// int knapsackRec(int weightKnapsack, int n, vector<int> val, vector<int> wt)
// {
//     if (n == 0 || weightKnapsack == 0)
//     {
//         return 0;
//     }
//     if (dp.empty())
//     {
//         dp.assign(n + 1, vector<int>(weightKnapsack + 1, -1));
//     }

//     if (dp[n][weightKnapsack] != -1)
//     {
//         return dp[n][weightKnapsack];
//     }
//     else
//     {
//         if (wt[n - 1] <= weightKnapsack)
//         {
//             int incl = knapsackRec(weightKnapsack - wt[n - 1], n - 1, val, wt) + val[n - 1];
//             int excl = knapsackRec(weightKnapsack, n - 1, val, wt);

//             return dp[n][weightKnapsack] = max(incl, excl);
//         }
//         else
//         {
//             return dp[n][weightKnapsack] = knapsackRec(weightKnapsack, n - 1, val, wt);
//         }
//     }
// }

// Tabulation
int tabKnap(int w, int n, vector<int> val, vector<int> wt)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0)); // Used 0 as we need to use the zero values later on

    for (int i = 1; i <= n; i++) // Not the idx it represents the item
    {
        for (int j = 1; j <= w; j++) // the current size of the knapsack
        {
            int itemVal = val[i - 1];
            int itemWt = wt[i - 1];

            if (itemWt <= j) // Item is selected
            {
                // Max(Accept, Reject Cases)
                dp[i][j] = max(dp[i - 1][j - itemWt] + itemVal, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7, n = 5;

    cout << tabKnap(w, n, val, wt) << endl;
    return 0;
}