#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // TODO: implement your logic here
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] - (mid + 1) < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (high == -1)
        {
            return k;
        }

        int more_missing = k - (arr[high] - (high + 1));
        return arr[high] + more_missing;
    }
};

/* ---------- Test Runner ---------- */

void runTest(vector<int> arr, int k, int expected)
{
    Solution sol;
    int result = sol.findKthPositive(arr, k);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "| k = " << k << endl;

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    // Example 1
    runTest({2, 3, 4, 7, 11}, 5, 9);

    // Example 2
    runTest({1, 2, 3, 4}, 2, 6);

    runTest({2}, 1, 1);

    // Edge case: missing starts from 1
    runTest({5, 6, 7}, 1, 1);

    // Edge case: all first k missing
    runTest({10}, 5, 5);

    // Edge case: single element array
    runTest({1}, 1, 2);

    return 0;
}
