#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool pallindrome(string ch, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (ch[i] != ch[j])
            return false;
    }
    return true;
}

void f(string s, vector<string> &ds, vector<vector<string>> &ans)
{

    if (s.length() == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        string first = s.substr(0, i + 1);
        string second = "";

        if (s.length() - i != 1)
            second = s.substr(i + 1, s.length());

        if (pallindrome(first, i + 1))
        {
            ds.push_back(first);
            f(second, ds, ans);
            ds.pop_back();
        }
    }

    return;
}

vector<vector<string>> partition(string s)
{
    vector<string> ds;
    vector<vector<string>> ans;

    f(s, ds, ans);

    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> ans = partition(s);

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