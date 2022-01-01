#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size() - 1;
    int row_start = 0;
    int col_end = n;

    while (row_start < col_end)
    {
        for (int i = row_start; i < col_end; i++)
        {
            int temp1 = matrix[i][col_end];

            matrix[i][col_end] = matrix[row_start][i];

            int temp2 = matrix[col_end][col_end + row_start - i];

            matrix[col_end][col_end + row_start - i] = temp1;

            int temp3 = matrix[col_end + row_start - i][row_start];

            matrix[col_end + row_start - i][row_start] = temp2;

            matrix[row_start][i] = temp3;
        }
        row_start++;
        col_end--;
    }
}
void swap(vector<vector<int>> &matrix, int i, int j)
{
    int temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
}
void transpose(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix, i, j);
        }
    }
}
void reflect(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void _rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    transpose(matrix, n);
    reflect(matrix, n);
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    _rotate(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}