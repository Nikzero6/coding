#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> global_row{9, vector<int>(10, 0)};
vector<vector<int>> global_col{9, vector<int>(10, 0)};
vector<int> sub_box1(10, 0);
vector<int> sub_box2(10, 0);
vector<int> sub_box3(10, 0);
vector<int> sub_box4(10, 0);
vector<int> sub_box5(10, 0);
vector<int> sub_box6(10, 0);
vector<int> sub_box7(10, 0);
vector<int> sub_box8(10, 0);
vector<int> sub_box9(10, 0);

void f(int i, int j, int start, vector<vector<char>> &board)
{
    if (i == 9)
    {
        return;
    }
    vector<int> *sub_box;
    if (i >= 0 && i < 3 && j >= 0 && j < 3)
        sub_box = &sub_box1;
    else if (i >= 0 && i < 3 && j >= 3 && j < 6)
        sub_box = &sub_box2;
    else if (i >= 0 && i < 3 && j >= 6 && j < 9)
        sub_box = &sub_box3;
    else if (i >= 3 && i < 6 && j >= 0 && j < 3)
        sub_box = &sub_box4;
    else if (i >= 3 && i < 6 && j >= 3 && j < 6)
        sub_box = &sub_box5;
    else if (i >= 3 && i < 6 && j >= 6 && j < 9)
        sub_box = &sub_box6;
    else if (i >= 6 && i < 9 && j >= 0 && j < 3)
        sub_box = &sub_box7;
    else if (i >= 6 && i < 9 && j >= 3 && j < 6)
        sub_box = &sub_box8;
    else if (i >= 6 && i < 9 && j >= 6 && j < 9)
        sub_box = &sub_box9;

    if (board[i][j] == '.')
    {
        for (int num = start; num < 10; num++)
        {
            if (!global_row[i][num] && !global_col[j][num] && !(*sub_box)[num])
            {
                board[i][j] = num + '0';
                global_row[i][num] = 1;
                global_col[j][num] = 1;
                (*sub_box)[num] = 1;
                if (j == 8)
                {
                    f(i + 1, 0, 1, board);
                }
                else
                    f(i, j + 1, num + 1, board);
                board[i][j] = '.';
                global_row[i][num] = 0;
                global_col[j][num] = 0;
                (*sub_box)[num] = 0;
            }
        }
        if (board[i][j] == '.')
            return;
    }
    else if (j == 8)
    {
        f(i + 1, 0, 1, board);
    }
    else
        f(i, j + 1, 1, board);
}

void solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
                global_row[i][board[i][j] - '0'] = 1;
            if (board[i][j] != '.')
                global_col[j][board[i][j] - '0'] = 1;
            if (i >= 0 && i < 3 && j >= 0 && j < 3)
                sub_box1[board[i][j] - '0'] = 1;
            else if (i >= 0 && i < 3 && j >= 3 && j < 6)
                sub_box2[board[i][j] - '0'] = 1;
            else if (i >= 0 && i < 3 && j >= 6 && j < 9)
                sub_box3[board[i][j] - '0'] = 1;
            else if (i >= 3 && i < 6 && j >= 0 && j < 3)
                sub_box4[board[i][j] - '0'] = 1;
            else if (i >= 3 && i < 6 && j >= 3 && j < 6)
                sub_box5[board[i][j] - '0'] = 1;
            else if (i >= 3 && i < 6 && j >= 6 && j < 9)
                sub_box6[board[i][j] - '0'] = 1;
            else if (i >= 6 && i < 9 && j >= 0 && j < 3)
                sub_box7[board[i][j] - '0'] = 1;
            else if (i >= 6 && i < 9 && j >= 3 && j < 6)
                sub_box8[board[i][j] - '0'] = 1;
            else if (i >= 6 && i < 9 && j >= 6 && j < 9)
                sub_box9[board[i][j] - '0'] = 1;
        }
    }
    f(0, 0, 1, board);
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9, '.'));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }

    solveSudoku(board);

    for (auto it : board)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}