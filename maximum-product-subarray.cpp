#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int currMax = 1;
        int currMin = 1;
        int result = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            int tempMax = currMax;
            currMax = max(nums[i], max(nums[i] * currMax, nums[i] * currMin));
            currMin = min(nums[i], min(nums[i] * tempMax, nums[i] * currMin));
            result = max(result, currMax);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {3, -1, 4};
    cout << "Output: " << sol.maxProduct(nums1) << endl;

    vector<int> nums2 = {-2, 0, -1};
    cout << "Output: " << sol.maxProduct(nums2) << endl;

    vector<int> nums3 = {-2, 3, -4};
    cout << "Output: " << sol.maxProduct(nums3) << endl;

    return 0;
}
