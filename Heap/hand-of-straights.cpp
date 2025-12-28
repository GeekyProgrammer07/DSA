#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        map<int, int> freq;

        for (int x : hand)
        {
            freq[x]++;
        }

        while (!freq.empty())
        {
            int start = freq.begin()->first;

            for (int i = 0; i < groupSize; i++)
            {
                int req_card = start + i;
                if (freq[req_card] == 0)
                {
                    return false;
                }
                freq[req_card]--;
                if (freq[req_card] == 0)
                {
                    freq.erase(req_card);
                }
            }
        }

        return true;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> hand, int groupSize, bool expected)
{
    Solution sol;
    bool result = sol.isNStraightHand(hand, groupSize);

    cout << "Hand: ";
    for (int x : hand)
        cout << x << " ";
    cout << "| groupSize = " << groupSize << endl;

    cout << "Output: " << (result ? "true" : "false")
         << " | Expected: " << (expected ? "true" : "false") << endl;

    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 2, 3, 6, 2, 3, 4, 7, 8}, 3, true);

    // Example 2
    runTest({1, 2, 3, 4, 5}, 4, false);

    // Edge case: empty hand (should be true)
    runTest({}, 1, true);

    // Edge case: groupSize = 1 (always true)
    runTest({5, 3, 1, 9}, 1, true);

    // Edge case: single group but not consecutive
    runTest({1, 3, 5, 7}, 4, false);

    // Edge case: large duplicates
    runTest({2, 2, 2, 3, 3, 3}, 3, false);

    return 0;
}
