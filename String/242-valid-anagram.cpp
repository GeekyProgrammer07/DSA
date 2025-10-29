#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            arr[(s[i] - 'a')]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (arr[t[i] - 'a'] == 0)
            {
                return false;
            }
            arr[t[i] - 'a']--;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    vector<pair<string, string>> testCases = {
        {"anagram", "nagaram"}, // Expected: true
        {"rat", "car"},         // Expected: false
        {"", ""},               // Expected: true
        {"a", "ab"},            // Expected: false
        {"listen", "silent"}    // Expected: true
    };

    for (auto &tc : testCases)
    {
        cout << "s: \"" << tc.first << "\", t: \"" << tc.second << "\"\n";
        cout << "Output: " << (sol.isAnagram(tc.first, tc.second) ? "true" : "false") << "\n\n";
    }

    return 0;
}
