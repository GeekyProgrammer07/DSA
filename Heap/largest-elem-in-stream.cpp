#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // TODO: initialize data structures
        
    }
    
    int add(int val) {
        // TODO: implement logic
        return 0;
    }
};

/* ---------- Test Runner ---------- */

int main() {

    // Example 1
    {
        vector<int> nums = {4, 5, 8, 2};
        KthLargest kthLargest(3, nums);

        cout << kthLargest.add(3) << endl;   // Expected: 4
        cout << kthLargest.add(5) << endl;   // Expected: 5
        cout << kthLargest.add(10) << endl;  // Expected: 5
        cout << kthLargest.add(9) << endl;   // Expected: 8
        cout << kthLargest.add(4) << endl;   // Expected: 8
    }

    cout << "----------------------------" << endl;

    // Example 2
    {
        vector<int> nums = {7, 7, 7, 7, 8, 3};
        KthLargest kthLargest(4, nums);

        cout << kthLargest.add(2) << endl;   // Expected: 7
        cout << kthLargest.add(10) << endl;  // Expected: 7
        cout << kthLargest.add(9) << endl;   // Expected: 7
        cout << kthLargest.add(9) << endl;   // Expected: 8
    }

    return 0;
}
