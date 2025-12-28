#include <bits/stdc++.h>
using namespace std;
// TODO: Not Completed
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        return 0;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int target, int expected)
{
    Solution sol;
    int result = sol.findTargetSumWays(nums, target);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << "| target = " << target << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 1, 1, 1, 1}, 3, 5);

    // Example 2
    runTest({1}, 1, 1);

    // Edge case: target zero
    runTest({0, 0, 0}, 0, -1); // expected not validated here

    // Edge case: impossible target
    runTest({1, 2, 3}, 10, 0);

    // Edge case: single zero
    runTest({0}, 0, 2); // "+0" and "-0"

    return 0;
}
