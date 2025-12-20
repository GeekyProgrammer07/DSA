#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for (int x : nums)
        {
            sum += x;

            int rem = ((sum % k) + k) % k;

            if (mp.find(rem) != mp.end())
            {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int k, int expected)
{
    Solution sol;
    int result = sol.subarraysDivByK(nums, k);

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
    runTest({4, 5, 0, -2, -3, 1}, 5, 7);

    // Example 2
    runTest({5}, 9, 0);

    // Edge case: all zeros
    runTest({0, 0, 0}, 5, 6);

    // Edge case: negative numbers
    runTest({-1, 2, 9}, 2, 2);

    // Edge case: no valid subarrays
    runTest({1, 2, 3}, 7, 0);

    runTest({2, -6, 3, 1, 2, 8, 2, 1}, 7, 4);

    runTest({-5}, 5, 1);

    runTest({1, -10, 5}, 9, 1);

    return 0;
}
