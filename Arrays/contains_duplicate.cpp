#include <iostream>
#include <algorithm>
using namespace std;

bool containsDuplicate(int *arr, int n)
{
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr1[] = {1, 2, 3, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 3, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << (containsDuplicate(arr1, size1) ? "true" : "false") << endl;
    cout << (containsDuplicate(arr2, size2) ? "true" : "false") << endl;
    cout << (containsDuplicate(arr3, size3) ? "true" : "false") << endl;

    return 0;
}
