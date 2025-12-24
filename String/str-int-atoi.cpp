#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        long long ans = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // 3. Parse digits
        while (i < n && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;
            i++;
        }

        return sign * ans;
    }
};

/* ---------- Test Runner ---------- */

void runTest(const string &s, int expected)
{
    Solution sol;
    int result = sol.myAtoi(s);

    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest("42", 42);

    // Example 2
    runTest("   -042", -42);

    // Example 3
    runTest("1337c0d3", 1337);

    // Example 4
    runTest("0-1", 0);

    // Example 5
    runTest("words and 987", 0);

    // Edge cases
    runTest("", 0);                  // empty string
    runTest("+1", 1);                // explicit positive sign
    runTest("-2147483649", INT_MIN); // underflow
    runTest("2147483648", INT_MAX);  // overflow
    runTest("   +000000123", 123);   // leading spaces and zeros
    runTest("+-12", 0);              // invalid sign sequence

    return 0;
}
