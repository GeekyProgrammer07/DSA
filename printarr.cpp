#include <iostream>
#include <vector>

using namespace std;

void printArr(const vector<int> &arr, int index = 0) {
    if (index >= arr.size()) return;  // base case
    if (index == arr.size() - 1) {
        cout << "7" << endl;
        return;
    }
    cout << arr[index] << " ";
    printArr(arr, index + 1);
}

// int something = 0;

// void printArr(vector<int> &arr) {
//     if (something == arr.size() - 1)
//     {
//         cout << "7" << endl;
//         return;
//     }
//     cout << arr[something] << " ";
//     something++;
//     printArr(arr);
// }

int main() {
    vector<int> arr = {1,3,4,5,6,7};
    printArr(arr);
    return 0;
}