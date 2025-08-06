#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
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
    int arr[] = {43, 242, 34, 234, 234, 23, 423, 423, 423, 42, 34, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: ";
    printArray(arr, arrSize);

    selectionSort(arr, arrSize);

    cout << "After Sorting: ";
    printArray(arr, arrSize);
    return 0;
}