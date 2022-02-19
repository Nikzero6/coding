#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.rbegin(), intervals.rend());

    vector<vector<int>> merged_intervals;

    while (!intervals.empty())
    {
        vector<int> temp = intervals.back();
        int n = merged_intervals.size() - 1;

        if (merged_intervals.empty())
            merged_intervals.push_back(temp);
        else
        {
            if (merged_intervals[n][0] >= temp[0])
            {
                merged_intervals[n][1] = max(merged_intervals[n][1], temp[1]);
            }
            else
            {
                merged_intervals.push_back(temp);
            }
        }

        intervals.pop_back();
    }
    return merged_intervals;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> intervals(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> intervals[i][j];
        }
    }

    vector<vector<int>> ans = merge(intervals);

    for (auto it : ans)
    {
        for (auto value : it)
            cout << value << " ";

        cout << endl;
    }

    return 0;
}