#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if (dp.empty()) {
            dp.assign(n + 1, -1);
        }
        if (n == 0 || n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        } else {
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return dp[n];
        }
    }
};

/* ---------- Test Runner ---------- */

void runTest(int n, int expected)
{
    Solution sol;
    int result = sol.climbStairs(n);

    cout << "n = " << n << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest(2, 2);

    // Example 2
    runTest(3, 3);

    // Edge case: minimum n
    runTest(1, 1);

    // Edge case: larger n
    runTest(5, 8);

    // Stress test
    runTest(10, 89);

    return 0;
}
