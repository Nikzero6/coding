#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    for (auto interval : intervals)
    {
        if (merged.empty() || merged.back()[1] < interval[0])
            merged.push_back(interval);

        else
            merged.back()[1] = max(merged.back()[1], interval[1]);
    }

    return merged;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> intervals[i][j];
        }
    }

    intervals = merge(intervals);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}