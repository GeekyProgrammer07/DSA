#include <bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        int answer = 0;

        while (r < n)
        {
            if (nums[r] % 2 != 0)
                count++;

            while (count > k)
            {
                if (nums[l] % 2 != 0)
                    count--;
                l++;
            }

            if (count == k)
            {
                int m = l;
                while (m < n && nums[m] % 2 == 0)
                    m++;
                answer += (m - l + 1);
            }

            r++;
        }

        return answer;
    }
};

int main()
{
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 1, 2, 1, 1};
        int k = 3;
        int result = sol.numberOfSubarrays(nums, k);
        cout << "Example 1 result: " << result << " (expected: 2)" << endl;
    }

    // Example 2
    {
        vector<int> nums = {2, 4, 6};
        int k = 1;
        int result = sol.numberOfSubarrays(nums, k);
        cout << "Example 2 result: " << result << " (expected: 0)" << endl;
    }

    // Example 3
    {
        vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
        int k = 2;
        int result = sol.numberOfSubarrays(nums, k);
        cout << "Example 3 result: " << result << " (expected: 16)" << endl;
    }

    return 0;
}
