#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int maj1 = 0, maj2 = 0, count1 = 0, count2 = 0;

        for (int x : nums)
        {
            if (x == maj1)
                count1++;
            else if (x == maj2)
                count2++;
            else if (count1 == 0)
            {
                maj1 = x;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                maj2 = x;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        // SECOND PASS (mandatory)
        count1 = count2 = 0;
        for (int x : nums)
        {
            if (x == maj1)
                count1++;
            else if (x == maj2)
                count2++;
        }

        vector<int> answer;
        if (count1 > nums.size() / 3)
            answer.push_back(maj1);
        if (count2 > nums.size() / 3)
            answer.push_back(maj2);

        return answer;
    }
};

/* ---------- Utility Functions ---------- */

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ",";
    }
    cout << "]" << endl;
}

void runTest(vector<int> nums)
{
    Solution sol;
    vector<int> result = sol.majorityElement(nums);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: ";
    printVector(result);
    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest({3, 2, 3}); // Expected: [3]

    // Example 2
    runTest({1}); // Expected: [1]

    // Example 3
    runTest({1, 2}); // Expected: [1,2]

    // Edge case: no majority > n/3
    runTest({1, 2, 3, 4});

    // Edge case: large repetition
    runTest({2, 2, 1, 3, 2, 1, 1, 1});
    runTest({2, 2, 1, 3});

    return 0;
}
