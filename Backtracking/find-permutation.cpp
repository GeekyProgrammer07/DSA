#include <iostream>
using namespace std;

void printStr(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        printStr(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), answer + s[i]);
    }
}

int main()
{
    string s = "abc";
    printStr(s, "");
    return 0;
}