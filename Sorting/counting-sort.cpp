#include <iostream>
#include <climits>
using namespace std;

void countingSort(int *arr, int n)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        min = std::min(arr[i], min);
        max = std::max(arr[i], max);
    }

    int range = max - min + 1;
    int *freq = new int[range](); 

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (freq[i]--)
        {
            arr[index++] = i + min;
        }
    }

    delete[] freq; 
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

    countingSort(arr, arrSize);

    cout << "After Sorting: ";
    printArray(arr, arrSize);
    return 0;
}
