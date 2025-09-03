#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool closeStrings(string word1, string word2)
//     {
//         if (word1.length() != word2.length())
//             return false;

//         map<char,int> occurances;
//         sort(word1.begin(), word1.end());
//         int count = 0;
//         occurances.insert()

//         cout << word1 << endl;

//         return false;
//     }
// };

int main()
{
    Solution sol;

    // Example 1
    cout << (sol.closeStrings("abc", "bca") ? "Passed" : "Failed") << endl;

    // Example 2
    cout << (sol.closeStrings("a", "aa") ? "Passed" : "Failed") << endl;

    // Example 3
    cout << (sol.closeStrings("cabbba", "abbccc") ? "Passed" : "Failed") << endl;

    // Custom: different sets of characters
    cout << (sol.closeStrings("aabc", "ddaa") ? "Passed" : "Failed") << endl;

    // Custom: identical words
    cout << (sol.closeStrings("hello", "hello") ? "Passed" : "Failed") << endl;

    return 0;
}
