#include <iostream>
#include <vector>
using namespace std;

void change_row_col(char a, int row, int col, vector<string> &ds, int n)
{
    for (int i = 0; i < n; i++)
        ds[row][i] = a;

    for (int i = 0; i < n; i++)
        ds[i][col] = a;
}

void change_diagonal(char a, int row, int col, vector<string> &ds, int n)
{
    int i = row + 1, j = col + 1;

    while (i < n && j < n)
    {
        ds[i][j] = a;
        i++;
        j++;
    }

    i = row + 1, j = col - 1;

    while (i < n && j >= 0)
    {
        ds[i][j] = a;
        i++;
        j--;
    }
}
void g(int ind, int i, vector<string> ds, vector<vector<string>> &ans, int n);

void f(int ind, vector<string> ds, vector<vector<string>> &ans, int n)
{
    if (ind == n)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (ds[ind][i] == 'a')
        {
            g(ind, i, ds, ans, n);
        }
    }
}

void g(int ind, int i, vector<string> ds, vector<vector<string>> &ans, int n)
{
    change_row_col('.', ind, i, ds, n);
    change_diagonal('.', ind, i, ds, n);
    ds[ind][i] = 'Q';
    f(ind + 1, ds, ans, n);
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ds[i].push_back('a');
    }
    f(0, ds, ans, n);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);

    cout << endl;

    for (auto it : ans)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}