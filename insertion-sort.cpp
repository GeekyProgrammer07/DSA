#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && curr < arr[prev])
        {
            swap(arr[prev + 1], arr[prev]);
            prev--;
        }
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int arr[] = {423, 427, 42, 34, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: ";
    printArray(arr, arrSize);

    insertionSort(arr, arrSize);

    cout << "After Sorting: ";
    printArray(arr, arrSize);
    return 0;
}