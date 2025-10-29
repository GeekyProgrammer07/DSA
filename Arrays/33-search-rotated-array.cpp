#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int start, int end, int target)
    {
        if (start > end)
        {
            return -1;
        }
        int mid = start + (end - start) / 2;
        int index = -1;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target <= nums[mid])
            {
                index = search(nums, start, mid - 1, target);
            }
            else
            {
                index = search(nums, mid + 1, end, target);
            }
        }
        else
        {
            if (nums[mid] <= target && target <= nums[end])
            {
                index = search(nums, mid + 1, end, target);
            }
            else
            {
                index = search(nums, start, mid - 1, target);
            }
        }
        return index;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test 1: Expected = 4, Got = " << sol.search(nums1, 0, nums1.size() - 1, target1) << endl;

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test 2: Expected = -1, Got = " << sol.search(nums2, 0, nums2.size() - 1, target2) << endl;

    // Test Case 3
    vector<int> nums3 = {1};
    int target3 = 0;
    cout << nums3.size() - 1;
    cout << "Test 3: Expected = -1, Got = " << sol.search(nums3, 0, nums3.size() - 1, target3) << endl;

    // Additional Edge Cases
    vector<int> nums4 = {1};
    int target4 = 1;
    cout << "Test 4: Expected = 0, Got = " << sol.search(nums4, 0, nums4.size() - 1, target4) << endl;

    vector<int> nums5 = {6, 7, 1, 2, 3, 4, 5};
    int target5 = 3;
    cout << "Test 5: Expected = 4, Got = " << sol.search(nums5, 0, nums5.size() - 1, target5) << endl;

    vector<int> nums6 = {6, 7, 1, 2, 3, 4, 5};
    int target6 = 6;
    cout << "Test 6: Expected = 0, Got = " << sol.search(nums6, 0, nums6.size() - 1, target6) << endl;

    return 0;
}
