#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int startIndex, int mid, int endIndex)
{
    vector<int> temp;
    int i = startIndex;
    int j = mid + 1;

    while (i <= mid && j <= endIndex)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    //Pushing the rest of the elements
    if (i > mid)
    {
        while (j <= endIndex)
        {
            temp.push_back(arr[j++]);
        }
    }
    else
    {
        while (i <= mid)
        {
            temp.push_back(arr[i++]);
        }
    }

    // Copying Temp to Original Array
    for (int i = startIndex, j = 0; i <= endIndex; i++)
    {
        arr[i] = temp[j++];
    }
}

void mergeSort(vector<int> &arr, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }
    int mid = startIndex + (endIndex - startIndex) / 2;

    // Divide
    mergeSort(arr, startIndex, mid);   // Left Half
    mergeSort(arr, mid + 1, endIndex); // Right Half

    // Conquer
    merge(arr, startIndex, mid, endIndex);
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
    mergeSort(arr, 0, arr.size() - 1);
    cout << "After Sorting: ";
    printArray(arr, arr.size());
    return 0;
}