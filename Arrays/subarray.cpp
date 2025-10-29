#include <iostream>
using namespace std;

void subarray(int *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
             cout << endl;           
        }
        cout << endl;
        
    }
}

int main() {
    int arr[] = {2,3,4,5,6,7,8};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    subarray(arr, arrSize);
    return 0;
}