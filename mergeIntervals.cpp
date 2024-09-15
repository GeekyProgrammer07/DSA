#include <iostream>
#include <vector>
#include <algorithm>

#define all(a) (a).begin(), (a).end()

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty()) return {};
    
    sort(all(intervals));
    vector<vector<int>> final_intervals;
    final_intervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= final_intervals.back()[1])
        {
            final_intervals.back()[1] = max(final_intervals.back()[1], intervals[i][1]);
        }
        else
        {
            final_intervals.push_back(intervals[i]);
        }
    }
    return final_intervals;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);

    for (const auto &interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}
