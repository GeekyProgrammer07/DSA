#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0, end = numbers.size() - 1;
        while (start < end)
        {
            int currSum = numbers[start] + numbers[end];
            if (currSum > target)
            {
                end--;
            }
            else if (currSum < target)
            {
                start++;
            }
            else
            {
                return {start+1, end+1};
            }
        }

        return {};
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(numbers1, target1);
    cout << "Test 1: ";
    if (!result1.empty())
    {
        cout << "[" << result1[0] << "," << result1[1] << "]";
    }
    cout << endl;

    // Test Case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(numbers2, target2);
    cout << "Test 2: ";
    if (!result2.empty())
    {
        cout << "[" << result2[0] << "," << result2[1] << "]";
    }
    cout << endl;

    // Test Case 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = sol.twoSum(numbers3, target3);
    cout << "Test 3: ";
    if (!result3.empty())
    {
        cout << "[" << result3[0] << "," << result3[1] << "]";
    }
    cout << endl;

    return 0;
}
