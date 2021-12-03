#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int i = 0, j = 1;

    vector<vector<int>> merged;

    for (auto interval : intervals)
    {
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}
int main()
{
    int n, m = 2;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(m, 0));

    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cin >> intervals[i][j];
        }
    }

    vector<vector<int>> interval1 = merge(intervals);

    for (auto arr : interval1)
    {
        for (auto elem : arr)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}