#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int x : nums)
        {
            freq[x]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &p : freq)
        {
            pq.push({p.second, p.first});
        }

        vector<int> answer;
        for (int i = 0; i < k; i++)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> nums, int k, vector<int> expected)
{
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);

    auto sortVec = [](vector<int> &v)
    {
        sort(v.begin(), v.end());
    };

    sortVec(result);
    sortVec(expected);

    cout << "Nums: ";
    for (int x : nums)
        cout << x << " ";
    cout << "| k = " << k << endl;

    cout << "Output: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    cout << "Expected: ";
    for (int x : expected)
        cout << x << " ";
    cout << endl;

    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 1, 1, 2, 2, 3}, 2, {1, 2});

    // Example 2
    runTest({1}, 1, {1});

    // Example 3
    runTest({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2, {1, 2});

    // Edge case: k equals number of unique elements
    runTest({4, 4, 6, 6, 8}, 3, {4, 6, 8});

    return 0;
}
