#include <iostream>
using namespace std;

//Without Using Extra Space
void reverse_array(int *arr, int n) {
    int start_pointer = 0, end_pointer = n - 1;

    while (start_pointer < end_pointer)
    {
        swap(arr[start_pointer], arr[end_pointer]);
        start_pointer++;
        end_pointer--;
    }
}

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2,5,1,7,3,7,9,3};
    int n = sizeof(arr)/sizeof(int);

    cout << "Normal Array: ";
    print_array(arr, n);

    cout << "Reversed Arrat: ";
    reverse_array(arr,n);
    print_array(arr, n);

    return 0;
}

// Using Extra Space
// void reverse_array(int *arr, int n) {
//     int temp[n];
//     for (int i = 0; i < n; i++)
//     {
//         temp[i] = arr[n-i-1];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
    
// }