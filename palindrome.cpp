#include <iostream>
#include <cstring>
using namespace std;

bool check_palindrome(char arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] != arr[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    char str[] = {'r', 'a', 'c', 'e', 'e', 'a', 'r', '\0'};
    int n = strlen(str);
    cout << (check_palindrome(str, n) ? "true" : "false") << endl;
    return 0;
}