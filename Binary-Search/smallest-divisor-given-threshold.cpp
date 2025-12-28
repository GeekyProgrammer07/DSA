#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(vector<int> nums, int divisor)
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += (x + divisor - 1) / divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        vector<int> possible_divisors;
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (getSum(nums, mid) > threshold)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                possible_divisors.push_back(mid);
            }
        }
        return *min_element(possible_divisors.begin(), possible_divisors.end());
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int threshold, int expected)
{
    Solution sol;
    int result = sol.smallestDivisor(nums, threshold);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << "| Threshold = " << threshold << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 2, 5, 9}, 6, 5);

    // Example 2
    runTest({44, 22, 33, 11, 1}, 5, 44);

    // Edge case: threshold equals array size
    runTest({10, 10, 10}, 3, 10);

    // Edge case: single element
    runTest({100}, 1, 100);

    // Edge case: large threshold
    runTest({1, 2, 3, 4, 5}, 100, 1);

    runTest({21212,10101,12121}, 1000000, 1);

    return 0;
}
