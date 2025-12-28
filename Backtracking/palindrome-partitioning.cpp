#include <bits/stdc++.h>
using namespace std;
// TODO: Revisit
class Solution
{
public:
    bool isPalindrome(string partition)
    {
        string t = partition;
        reverse(t.begin(), t.end());
        return partition == t;
    }
    void createPartition(string s, vector<string> &partitions, vector<vector<string>> &answer)
    {
        if (s.size() == 0)
        {
            answer.push_back(partitions);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            string part = s.substr(0, i + 1);
            if (isPalindrome(part))
            {
                partitions.push_back(part);
                createPartition(s.substr(i + 1), partitions, answer);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> answer;
        vector<string> partitions;
        createPartition(s, partitions, answer);
        return answer;
    }
};

/* ---------- Utility Functions ---------- */

void printResult(const vector<vector<string>> &result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "\"" << result[i][j] << "\"";
            if (j + 1 < result[i].size())
                cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size())
            cout << ",";
    }
    cout << "]" << endl;
}

void runTest(const string &s)
{
    Solution sol;
    vector<vector<string>> result = sol.partition(s);

    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: ";
    printResult(result);
    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest("aab"); // Expected: [["a","a","b"],["aa","b"]]

    // Example 2
    runTest("a"); // Expected: [["a"]]

    // Edge case: all same characters
    runTest("aaa");

    // Edge case: no multi-length palindrome
    runTest("abc");

    // Edge case: maximum length
    runTest("racecar");

    return 0;
}
