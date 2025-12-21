#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // TODO: implement your logic here
        if (k <= 1)
        {
            return 0;
        }
        int l = 0, r = 0;
        int prod = 1, answer = 0;
        while (r < nums.size())
        {
            prod *= nums[r];
            if (prod < k)
            {
                answer += r - l + 1;
            }
            else
            {
                while (prod >= k)
                {
                    prod /= nums[l];
                    l++;
                }
                answer += r - l + 1;
            }
            r++;
        }

        return answer;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int k, int expected)
{
    Solution sol;
    int result = sol.numSubarrayProductLessThanK(nums, k);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << "| k = " << k << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({10, 5, 2, 6}, 100, 8);

    // Example 2
    runTest({1, 2, 3}, 0, 0);

    // Edge case: k = 1 (no positive product < 1)
    runTest({1, 1, 1}, 1, 0);

    // Edge case: single element
    runTest({5}, 10, 1);

    // Edge case: all products valid
    runTest({1, 2, 3}, 100, 6);

    return 0;
}
