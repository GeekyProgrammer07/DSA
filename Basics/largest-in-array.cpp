#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 2, 8, 1, 9};
    int max = arr[1];
    for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Largest element in the array: " << max << endl;
    return 0;
}