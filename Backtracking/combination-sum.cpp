#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> answer;
    set<vector<int>> s;
    void getCombinations(int i, int target, vector<int> &temp, vector<int> &candidates)
    {
        if (i == candidates.size() || target < 0)
        {
            return;
        }
        if (target == 0)
        {
            if (s.find(temp) == s.end())
            {
                s.insert(temp);
                answer.push_back(temp);
                return;
            }
            return;
        }
        // Choice 1: include the element once
        temp.push_back(candidates[i]);
        getCombinations(i + 1, target - candidates[i], temp, candidates);
        // Choice 2: include the element multiple times
        getCombinations(i, target - candidates[i], temp, candidates);
        // Choice 3: dont include the elemnt
        temp.pop_back(); // Beacase the first element needs to be removed which came form previos state
        getCombinations(i + 1, target, temp, candidates);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        getCombinations(0, target, temp, candidates);
        return answer;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> answer;
//     void getCombinations(int i, int target, vector<int> &temp, vector<int> &candidates, int size)
//     {
//         if (target == 0 || i >= candidates.size())
//         {
//             answer.push_back(temp);
//             return;
//         }

//         if (target < 0)
//         {
//             return;
//         }

//         for (int idx = i; idx < size; idx++)
//         {
//             if (candidates[idx] <= target)
//             {

//                 temp.push_back(candidates[idx]);
//                 getCombinations(idx, target - candidates[idx], temp, candidates, size);
//                 temp.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
// //         vector<int> temp;
//         getCombinations(0, target, temp, candidates, candidates.size());
//         return answer;
//     }
// };

/* ---------- Utility Functions ---------- */

void printResult(const vector<vector<int>> &result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < result[i].size())
                cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size())
            cout << ",";
    }
    cout << "]" << endl;
}

void runTest(vector<int> candidates, int target)
{
    Solution sol;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Candidates: ";
    for (int x : candidates)
        cout << x << " ";
    cout << "| Target = " << target << endl;

    cout << "Output: ";
    printResult(result);

    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest({2, 3, 6, 7}, 7); // Expected: [[2,2,3],[7]]

    // Example 2
    runTest({2, 3, 5}, 8); // Expected: [[2,2,2,2],[2,3,3],[3,5]]

    // Example 3
    runTest({2}, 1); // Expected: []

    // Edge case: single candidate equals target
    runTest({5}, 5); // Expected: [[5]]

    // Edge case: no combination possible
    runTest({4, 6}, 3); // Expected: []

    return 0;
}
