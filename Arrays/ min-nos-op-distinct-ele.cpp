#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isDisntinct(vector<int> &nums, int i)
    {
        for (i; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    int minOperations(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i <= nums.size() - 3; i = i + 3)
        {
            if (isDisntinct(nums, i))
            {
                return count;
            }
            count++;
        }

        return count;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.minimumOperations(nums);

    cout << "Nums: ";
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
    runTest({3, 8, 3, 6, 5, 8}, 1);

    // Example 2
    runTest({2, 2}, 1);

    // Example 3
    runTest({4, 3, 5, 1, 2}, 0);

    // Edge case: single element
    runTest({7}, 0);

    // Edge case: exactly three elements with duplicates
    runTest({1, 2, 1}, 1);

    // Edge case: large prefix duplicates
    runTest({5, 5, 5, 6, 7, 8}, 1);

    return 0;
}
