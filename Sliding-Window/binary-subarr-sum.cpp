#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int l = 0, r = 0, answer = 0, sum = 0;

        while (r < nums.size())
        {
            if (nums[r] == 1)
            {
                sum++;
            }

            while (sum > goal)
            {
                if (nums[l] == 1)
                    sum--;
                l++;
            }

            if (sum == goal)
            {
                int m = l;
                while (m < nums.size() && nums[m] != 1)
                {
                    m++;
                }
                answer += m - l + 1;
            }
            r++;
        }
        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 0, 1, 0, 1};
        int goal = 2;
        cout << "Example 1 output: " << sol.numSubarraysWithSum(nums, goal) << '\n';
    }

    // Example 2
    {
        vector<int> nums = {0, 0, 0, 0, 0};
        int goal = 0;
        cout << "Example 2 output: " << sol.numSubarraysWithSum(nums, goal) << '\n';
    }

    return 0;
}
