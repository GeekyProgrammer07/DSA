#include <bits/stdc++.h>
using namespace std;
// TODO: Not Completed
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prevRobbed = 0;
        int prevNotRobbed = 0;

        if (nums.size() == 1)
        {
            return nums[0];
        }
        // Ignoring Last Element
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int currentRobbed = prevNotRobbed + nums[i];
            int currentNotRobbed = max(prevRobbed, prevNotRobbed);

            prevRobbed = currentRobbed;
            prevNotRobbed = currentNotRobbed;
        }

        int max1 = max(prevRobbed, prevNotRobbed);

        prevRobbed = 0;
        prevNotRobbed = 0;

        // Ignoring the first element
        for (int i = 1; i < nums.size(); i++)
        {
            int currentRobbed = prevNotRobbed + nums[i];
            int currentNotRobbed = max(prevRobbed, prevNotRobbed);

            prevRobbed = currentRobbed;
            prevNotRobbed = currentNotRobbed;
        }

        int max2 = max(prevRobbed, prevNotRobbed);

        return max(max1, max2);
    }
};

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
    runTest({2, 3, 2}, 3);

    // Example 2
    runTest({1, 2, 3, 1}, 4);

    // Example 3
    runTest({1, 2, 3}, 3);

    // Edge case: single house
    runTest({5}, 5);

    // Edge case: two houses
    runTest({2, 7}, 7);

    // Edge case: all zeros
    runTest({0, 0, 0, 0}, 0);

    return 0;
}
