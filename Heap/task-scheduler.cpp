#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        priority_queue<int> pq;

        for (char c : tasks)
            freq[c]++;
        for (auto &p : freq)
            pq.push(p.second);

        int time = 0;
        deque<pair<int, int>> q;

        while (!pq.empty() || !q.empty())
        {
            time++;
            if (!q.empty() && q.front().second <= time)
            {
                pq.push(q.front().first);
                q.pop_front();
            }

            if (!pq.empty())
            {
                int count = pq.top() - 1;
                pq.pop();
                if (count > 0)
                {
                    q.push_back({count, time + n + 1});
                }
            }
        }
        return time;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << sol.leastInterval(tasks1, n1) << endl; // Expected: 8

    // Test case 2
    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    cout << sol.leastInterval(tasks2, n2) << endl; // Expected: 6

    // Test case 3
    vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n3 = 3;
    cout << sol.leastInterval(tasks3, n3) << endl; // Expected: 10

    // Edge case: n = 0
    vector<char> tasks4 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n4 = 0;
    cout << sol.leastInterval(tasks4, n4) << endl; // Expected: 6

    // Single task
    vector<char> tasks5 = {'A'};
    int n5 = 5;
    cout << sol.leastInterval(tasks5, n5) << endl; // Expected: 1

    return 0;
}
