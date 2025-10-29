#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int startIndex, int endIndex)
{
    int i = startIndex - 1, pivotElement = arr[endIndex];
    for (int j = startIndex; j < endIndex; j++)
    {
        if (arr[j] <= pivotElement)
        {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[endIndex]);
    return i;
}

void quickSort(vector<int> &arr, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }

    int pivotIndex = partition(arr, startIndex, endIndex);

    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {6, 5, 2, 1, 3, 4};
    cout << "Before Sorting: ";
    printArray(arr, arr.size());
    quickSort(arr, 0, arr.size() - 1);
    cout << "After Sorting: ";
    printArray(arr, arr.size());
    return 0;
}