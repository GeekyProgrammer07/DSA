#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered;
        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }
        s = filtered;
        int start = 0, end = s.length() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    vector<string> testCases = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " ",
        "0P"};

    for (auto &tc : testCases)
    {
        cout << "Input: \"" << tc << "\"\n";
        cout << "Output: " << (sol.isPalindrome(tc) ? "true" : "false") << "\n\n";
    }

    return 0;
}
