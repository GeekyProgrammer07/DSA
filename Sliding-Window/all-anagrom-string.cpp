#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allZero(vector<int> &counter)
    {
        for (int &x : counter)
        {
            if (x != 0)
                return false;
        }
        return true;
    }

    int search(string &pat, string &txt)
    {
        // Make the pattern array like we are counting the freq
        vector<int> counter(26, 0);
        for (char &ch : pat)
        {
            counter[ch - 'a']++;
        }

        // Making the sliding window
        int i = 0, j = 0, result = 0;
        while (j < txt.length())
        {

            counter[txt[j] - 'a']--;

            if (j - i + 1 == pat.length())
            {
                if (allZero(counter))
                {
                    result++;
                }
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string pat = "for";
    string txt = "forxxorfxdofr";
    cout << sol.search(pat, txt) << endl;
    return 0;
}