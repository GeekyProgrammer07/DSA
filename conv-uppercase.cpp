#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[] = {'H', 'e', 'L', 'l', 'o', '\0'};
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            continue;
        int pos = arr[i] - 'a';
        arr[i] = (char)('A' + pos);
    }
    cout << arr << endl;
    return 0;
}