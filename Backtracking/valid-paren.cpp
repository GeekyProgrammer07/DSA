#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> answer;

    void something(int open, int close, string &temp)
    {
        if (open == close && open == 0)
        {
            answer.push_back(temp);
            return;
        }
        if (open > 0)
        {
            temp.push_back('(');
            something(open - 1, close, temp);
            temp.pop_back();
        }
        if (open < close)
        {
            temp.push_back(')');
            something(open, close - 1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        // TODO: implement your logic here
        string temp;
        something(n, n, temp);
        return answer;
    }
};

/* ---------- Utility Functions ---------- */

void printResult(const vector<string> &result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\"" << result[i] << "\"";
        if (i + 1 < result.size())
            cout << ",";
    }
    cout << "]" << endl;
}

void runTest(int n)
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "n = " << n << endl;
    cout << "Output: ";
    printResult(result);
    cout << "-----------------------------------" << endl;
}

/* ---------- Test Runner ---------- */

int main()
{

    // Example 1
    runTest(3); // Expected: ["((()))","(()())","(())()","()(())","()()()"]

    // Example 2
    // runTest(1); // Expected: ["()"]

    // // Edge case: minimum n
    // runTest(1);

    // // Edge case: n = 2
    // runTest(2); // Expected: ["(())","()()"]

    // // Edge case: maximum constraint
    // runTest(8);

    return 0;
}
