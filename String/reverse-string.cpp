#include <iostream>
#include <cstring>
using namespace std;

void reverse_arr(char arr[], int n)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    char str[] = {'a', 'g', 'e', 'i', '\0'};
    int n = strlen(str);
    reverse_arr(str, n);
    cout << str << endl;
    return 0;
}