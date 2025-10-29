#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;

        int tempArr1[26] = {0};
        int tempArr2[26] = {0};

        for (int i = 0; i < word1.length(); i++) {
            tempArr1[word1[i] - 'a']++;
            tempArr2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((tempArr1[i] == 0) != (tempArr2[i] == 0))
                return false;
        }

        sort(tempArr1, tempArr1 + 26);
        sort(tempArr2, tempArr2 + 26);

        for (int i = 0; i < 26; i++) {
            if (tempArr1[i] != tempArr2[i])
                return false;
        }

        return true;
    }
};


void runTest(Solution &sol, const string &w1, const string &w2, bool expected, int testNo)
{
    bool result = sol.closeStrings(w1, w2);
    if (result == expected)
        cout << "✅ Test " << testNo << " PASSED (" << w1 << ", " << w2 << ")" << endl;
    else
        cout << "❌ Test " << testNo << " FAILED (" << w1 << ", " << w2 << ") => Got "
             << boolalpha << result << ", Expected " << expected << endl;
}

int main()
{
    Solution sol;

    vector<tuple<string, string, bool>> tests = {
        {"abc", "bca", true},                                      // Example 1
        {"a", "aa", false},                                        // Example 2
        {"cabbba", "abbccc", true},                                // Example 3
        {"aabbzz", "zzbbaa", true},                                // Same chars, different order
        {"aabbcc", "aabbc", false},                                // Different lengths
        {"abc", "def", false},                                     // Different characters entirely
        {"abbzzca", "babzzcz", false},                              // Swaps and transformations possible
        {"aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff", false}, // Same letters, different frequency pattern
        {"aabb", "ab", false},                                     // Cannot remove characters
        {"xxyyzz", "yyxxzz", true}                                 // Just reordered characters
    };

    int testNo = 1;
    for (auto &[w1, w2, expected] : tests)
        runTest(sol, w1, w2, expected, testNo++);

    return 0;
}
