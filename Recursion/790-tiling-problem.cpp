#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1 || n == 0)
        {
            return 1;
        }

        return numTilings(n-1) + numTilings(n-2);
    }
};

int main() {
    Solution sol;

    cout << (sol.numTilings(4) == 5 ? "Passed" : "Failed") << endl;
    cout << (sol.numTilings(1) == 1 ? "Passed" : "Failed") << endl;
    cout << (sol.numTilings(2) == 2 ? "Passed" : "Failed") << endl;

    return 0;
}
