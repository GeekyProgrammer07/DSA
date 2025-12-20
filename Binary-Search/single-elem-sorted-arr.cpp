#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // TODO: implement your logic here
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid == nums.size() - 1)
            {
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid - 1] != nums[mid]) || (mid % 2 == 0 && nums[mid + 1] != nums[mid]))
            {
                high = mid - 1;
            }
            else
            {

                low = mid + 1;
            }
        }

        return nums[low];
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.singleNonDuplicate(nums);

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
    runTest({1, 1, 2, 3, 3, 4, 4, 8, 8}, 2);

    // Example 2
    runTest({3, 3, 7, 7, 10, 11, 11}, 10);

    // Edge case: single element array
    runTest({5}, 5);

    // Edge case: single element at start
    runTest({1, 2, 2, 3, 3}, 1);

    // Edge case: single element at end
    runTest({1, 1, 2, 2, 9}, 9);

    return 0;
}
