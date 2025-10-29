#include <iostream>
using namespace std;

void printSubs(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << endl;
        return;
    }

    printSubs(s.substr(1, s.length() - 1), answer + s[0]);
    printSubs(s.substr(1, s.length() - 1), answer);
}

int main()
{
    string s = "abc";
    printSubs(s, "");
    return 0;
}
