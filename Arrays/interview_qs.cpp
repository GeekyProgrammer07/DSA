#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkSubsequence(int start, int end, string s){
    while (start < end)
    {
        if((int)(s[start]) >= (int)(s[start + 1])) {
            return false;
        }
        start++;
    }
    return true;
}

int countIncreasingSequences(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); ) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            int start = i+1;
            i++;
            
            while(isdigit(s[i])) {
                i++;
            }
            int end = i - 1;
            if(checkSubsequence(start,end,s) && i != s.length()) {
                count++;
            }
        } else {
            i++;
        }
    }
    return count;
}

void runTest(const string &s, int expected, int testNo) {
    int result = countIncreasingSequences(s);
    if (result == expected)
        cout << "✅ Test " << testNo << " PASSED (" << s << ") => " << result << endl;
    else
        cout << "❌ Test " << testNo << " FAILED (" << s << ") => Got " << result << ", Expected " << expected << endl;
}

int main() {
    vector<pair<string, int>> tests = {
        {"a123b45c798d789", 2},      // normal case
        {"a111b222c333d", 0},        // equal digits not increasing
        {"a135b246c357d", 3},        // all increasing
        {"123a45b", 1},              // prefix digits ignored
        {"a9b8c7d6e5f", 5},          // single digits all valid
        {"a987b123c321d", 1},        // only 123 is increasing
        {"x12y21z", 1},              // only 12 is increasing
        {"a1b2c3", 2},               // all single digits valid
        {"a123b45c798", 2},          // last 798 ignored (no letter after)
        {"a1b22c333d4444e", 1}       // only single digits count (1)
    };

    int testNo = 1;
    for (auto &t : tests)
        runTest(t.first, t.second, testNo++);
    
    return 0;
}