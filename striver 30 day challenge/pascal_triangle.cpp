#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    if (numRows == 0)
    {
        return vector<vector<int>>({{}});
    }
    else if (numRows == 1)
    {
        return vector<vector<int>>({{1}});
    }
    else if (numRows == 2)
    {
        return vector<vector<int>>({{1}, {1, 1}});
    }
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    ans[1].push_back(1);
    ans[1].push_back(1);

    for (int i = 2; i < numRows; i++)
    {
        ans[i].push_back(1);

        for (int j = 1; j < i; j++)
        {
            ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        ans[i].push_back(1);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> pascal = generate(n);

    for (int i = 0; i < pascal.size(); i++)
    {
        for (int j = 0; j < pascal[i].size(); j++)
        {
            cout << pascal[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}