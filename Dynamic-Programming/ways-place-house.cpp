#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> dp;
    const long long MOD = 1e9 + 7;

    long long ways(int n)
    {
        if (dp.empty())
            dp.assign(n + 1, -1);

        if (n == 0)
            return 1;
        if (n == 1)
            return 2;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (ways(n - 1) + ways(n - 2)) % MOD;
    }

    int countHousePlacements(int n)
    {
        long long oneSide = ways(n);
        return (oneSide * oneSide) % MOD;
    }
};

/* ---------- Test Runner ---------- */

void runTest(int n, int expected)
{
    Solution sol;
    int result = sol.countHousePlacements(n);

    cout << "n = " << n << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest(1, 4);

    // Example 2
    runTest(2, 9);

    // Edge case: n = 3
    runTest(3, -1); // expected value not checked here

    // Edge case: maximum constraint
    runTest(10000, -1); // stress test, expected not validated

    return 0;
}
