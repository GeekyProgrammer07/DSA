#include <iostream>

using namespace std;

int binary_search(int *arr, int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 3, 5, 6, 7, 7, 7, 8};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int index = binary_search(arr, arrSize, 6);

    cout << "Index: " << index << endl;

    return 0;
}