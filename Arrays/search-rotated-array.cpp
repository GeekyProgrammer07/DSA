#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Output: " << sol.search(nums1, target1) << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Output: " << sol.search(nums2, target2) << endl;

    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Output: " << sol.search(nums3, target3) << endl;

    return 0;
}
