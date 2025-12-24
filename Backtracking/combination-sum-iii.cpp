#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> s;
    void combinations(int num, int target, vector<int> &combination, vector<vector<int>> &answer, int combSize)
    {
        if (target == 0)
        {
            if (s.find(combination) == s.end() && combination.size() == combSize)
            {
                answer.push_back(combination);
                s.insert(combination);
            }
            return;
        }
        
        if (num == 10)
        {
            return;
        }

        combination.push_back(num);
        combinations(num + 1, target - num, combination, answer, combSize);
        combination.pop_back();
        combinations(num + 1, target, combination, answer, combSize);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> answer;
        vector<int> combination;
        combinations(1, n, combination, answer, k);
        return answer;
    }
};

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

void runTest(int k, int n)
{
    Solution sol;
    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "k = " << k << ", n = " << n << endl;
    cout << "Output: ";
    printResult(result);
    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest(3, 7); // Expected: [[1,2,4]]

    // Example 2
    runTest(3, 9); // Expected: [[1,2,6],[1,3,5],[2,3,4]]

    // Example 3
    runTest(4, 1); // Expected: []

    // Edge case: minimum k and n
    runTest(2, 3); // Expected: [[1,2]]

    // Edge case: maximum k
    runTest(9, 45); // Expected: [[1,2,3,4,5,6,7,8,9]]

    return 0;
}
