#include <iostream>
#include <vector>
using namespace std;
void makeColZero(vector<vector<int>> &matrix, int j)
{
    for (int row = 0; row < matrix.size(); row++)
        matrix[row][j] = 0;
}
void makeRowZero(vector<vector<int>> &matrix, int i)
{
    for (int col = 0; col < matrix[0].size(); col++)
        matrix[i][col] = 0;
}
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int arr2[col] = {0};
    int arr1[row] = {0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                arr2[j]++;
                arr1[i]++;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr1[i])
                makeRowZero(matrix, i);
            if (arr2[j])
                makeColZero(matrix, j);
        }
    }
}

//-------------------------------------------------
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        bool isCol = false;

        for (int i = 0; i < row; i++)
        {
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }
        if (isCol)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

//-----------------------------------------------------
int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}