/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;

// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else if (zeroCount > 0) {
                swap(nums, i, i - zeroCount);
            }
        }
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
// @lc code=end

