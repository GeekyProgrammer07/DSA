#include <iostream>
#include <vector>
using namespace std;

// bool checkSorted(vector<int> &arr, int n)
// {
//     // Base case: An array with 0 or 1 elements is always sorted.
//     if (n <= 1)
//     {
//         return true;
//     }
//     return (arr[n - 1] >= arr[n - 2]) && checkSorted(arr, n - 1);
// }

bool checkSorted(vector<int> &arr, int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }
    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    return checkSorted(arr, n, i + 1);
}

int main()
{
    vector<int> arr = {3, 6, 7, 9, 1};
    int length = arr.size();
    cout << (checkSorted(arr, length, 0) ? "Array is Sorted" : "Array is not sorted") << endl;
    return 0;
}