#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &arr, int i, int elem)
{
    if (i == arr.size())
    {
        return -1;
    }
    if (arr[i] == elem)
    {
        return i;
    }
    return firstOccurence(arr, i + 1, elem);
}

int lastOccurence(vector<int> &arr, int i, int elem)
{
    if (i == arr.size())
    {
        return -1;
    }
    int index = lastOccurence(arr, i + 1, elem);
    if (index == -1 && arr[i] == elem)
    {
        return i;
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 6, 7, 7, 7, 7, 3, 54, 8, 1};
    // cout << firstOccurence(arr,0,58) << endl;
    cout << lastOccurence(arr, 0, 7) << endl;
    return 0;
}