#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void removeDuplicateLetters(string s, bool *tracked, string ans, int index = 0)
    {
        if (index == s.length())
        {
            cout << ans << endl;
            return;
        }

        if (tracked[(int)(s[index] - 'a')])
        {
            removeDuplicateLetters(s, tracked, ans, index + 1);
        }
        else
        {
            tracked[(int)(s[index] - 'a')] = true;
            removeDuplicateLetters(s, tracked, ans + s[index], index + 1);
        }
    }
};

int main()
{
    Solution s;
    string name = "aapnnacollege";
    bool tracked[26] = {false};
    string answer = "";
    s.removeDuplicateLetters(name, tracked, answer);
    return 0;
}