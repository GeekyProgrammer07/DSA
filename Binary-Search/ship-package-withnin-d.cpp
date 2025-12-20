#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> weights, int capacity, int totalDays)
    {
        int day = 1, load = 0;
        for (int x : weights)
        {
            if (load + x > capacity)
            {
                day++;
                load = x;
            }
            else
            {
                load += x;
            }
        }
        if (day > totalDays)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        // TODO: implement your logic here
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(weights, mid, days))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> weights, int days, int expected)
{
    Solution sol;
    int result = sol.shipWithinDays(weights, days);

    cout << "Weights: ";
    for (int w : weights)
        cout << w << " ";
    cout << "| Days = " << days << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 15);

    // Example 2
    runTest({3, 2, 2, 4, 1, 4}, 3, 6);

    // Example 3
    runTest({1, 2, 3, 1, 1}, 4, 3);

    // Edge case: single day (must take all)
    runTest({5, 5, 5, 5}, 1, 20);

    // Edge case: days equal to number of packages
    runTest({1, 2, 3, 4}, 4, 4);

    return 0;
}
