#include <iostream>
using namespace std;

int linear_search(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {3,6,7,98,2,3,5,56,7};
    int n = sizeof(arr)/sizeof(int);
    int index = linear_search(arr, n, 5);

    cout << index << endl;
    return 0;
}