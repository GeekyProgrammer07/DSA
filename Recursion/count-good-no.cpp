#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const long long MOD = 1e9 + 7;

    long long expo(long long x, long long n)
    {
        if (n == 0)
            return 1;
        long long half = expo((x * x) % MOD, n / 2);
        if (n % 2 == 0)
            return half;
        return (x * half) % MOD;
    }

    int countGoodNumbers(long long n)
    {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        return (expo(5, evenPos) * expo(4, oddPos)) % MOD;
    }
};

/* ---------- Test Runner ---------- */

void runTest(long long n, int expected)
{
    Solution sol;
    int result = sol.countGoodNumbers(n);

    cout << "n = " << n << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest(1, 5);

    // Example 2
    runTest(4, 400);

    // Example 3
    runTest(50, 564908303);

    // Edge case: smallest n
    runTest(1, 5);

    return 0;
}
