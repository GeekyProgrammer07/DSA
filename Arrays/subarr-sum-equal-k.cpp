#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // TODO: implement your logic here
        map<int, int> mp;
        mp[0] = 1;
        int count = 0, sum = 0;
        for (int x : nums)
        {
            sum += x;
            if (mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int k, int expected)
{
    Solution sol;
    int result = sol.subarraySum(nums, k);

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
    runTest({1, 1, 1}, 2, 2);

    // Example 2
    runTest({1, 2, 3}, 3, 2);

    // Edge case: single element equals k
    runTest({5}, 5, 1);

    // Edge case: negative numbers
    runTest({1, -1, 0}, 0, 3);

    // Edge case: no valid subarrays
    runTest({1, 2, 3}, 10, 0);

    return 0;
}
