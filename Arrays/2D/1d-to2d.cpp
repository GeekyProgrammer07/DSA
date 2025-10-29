#include <iostream>
using namespace std;

class Solution {
public:
    bool construct2DArray(int original[], int originalSize, int m, int n, int result[][100]) {
        
        return false; // placeholder
    }
};

int main() {
    Solution sol;
    int result[100][100];

    // Example Test 1
    int original1[] = {1, 2, 3, 4};
    int m1 = 2, n1 = 2;
    int size1 = sizeof(original1) / sizeof(original1[0]);
    cout << (sol.construct2DArray(original1, size1, m1, n1, result) ? "Filled" : "[]") << endl;

    // Example Test 2
    int original2[] = {1, 2, 3};
    int m2 = 1, n2 = 3;
    int size2 = sizeof(original2) / sizeof(original2[0]);
    cout << (sol.construct2DArray(original2, size2, m2, n2, result) ? "Filled" : "[]") << endl;

    // Example Test 3
    int original3[] = {1, 2};
    int m3 = 1, n3 = 1;
    int size3 = sizeof(original3) / sizeof(original3[0]);
    cout << (sol.construct2DArray(original3, size3, m3, n3, result) ? "Filled" : "[]") << endl;

    return 0;
}
