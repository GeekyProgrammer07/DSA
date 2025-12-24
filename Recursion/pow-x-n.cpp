#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long double myPow(double x, long long n)
    {
        // TODO: implement your logic here
        if (n == 0)
            return 1;
        if (n < 0)
        {
            return myPow(1 / x, -n);
        }
        if (n % 2 == 0)
        {
            return myPow(x * x, n / 2);
        }
        return x * myPow(x * x, (n - 1) / 2);
    }
};

/* ---------- Test Runner ---------- */

void runTest(double x, int n, double expected)
{
    Solution sol;
    double result = sol.myPow(x, n);

    cout << fixed << setprecision(5);
    cout << "x = " << x << ", n = " << n << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest(2.00000, 10, 1024.00000);

    // Example 2
    runTest(2.10000, 3, 9.26100);

    // Example 3
    runTest(2.00000, -2, 0.25000);

    // Edge case: n = 0
    runTest(5.12345, 0, 1.00000);

    // Edge case: x = 1
    runTest(1.00000, -1000000000, 1.00000);

    // Edge case: negative base, odd power
    runTest(-2.00000, 3, -8.00000);
    runTest(2.00, -200000000, -8.00000);

    return 0;
}
