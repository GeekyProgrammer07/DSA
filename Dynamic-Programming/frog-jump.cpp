#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    bool answer(int currentStone, int prevJump, vector<int> &stones, unordered_map<int, int> &mp)
    {
        if (currentStone == stones.back())
            return true;

        int idx = mp[currentStone];

        if (dp[idx][prevJump] != -1)
            return dp[idx][prevJump];

        for (int i = -1; i <= 1; i++)
        {
            int nextJump = prevJump + i;
            if (nextJump <= 0)
                continue;

            int nextStone = currentStone + nextJump;

            if (mp.count(nextStone))
            {
                if (answer(nextStone, nextJump, stones, mp))
                    return dp[idx][prevJump] = true;
            }
        }

        return dp[idx][prevJump] = false;
    }

    bool canCross(vector<int> &stones)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < stones.size(); i++)
            mp[stones[i]] = i;

        dp.assign(stones.size(), vector<int>(stones.size(), -1));

        return answer(0, 0, stones, mp);
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> stones, bool expected)
{
    Solution sol;
    bool result = sol.canCross(stones);

    cout << "Stones: ";
    for (int x : stones)
        cout << x << " ";
    cout << endl;

    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({0, 1, 3, 5, 6, 8, 12, 17}, true);

    // Example 2
    runTest({0, 1, 2, 3, 4, 8, 9, 11}, false);

    // Edge case: minimum valid crossing
    runTest({0, 1}, true);

    // Edge case: impossible first jump
    runTest({0, 2}, false);

    // Edge case: large gaps later
    runTest({0, 1, 3, 6, 10, 15, 21}, true);

    return 0;
}
