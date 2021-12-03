#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> base2To6Hire2020(vector<bool> base2)
{
    int deci = 0;
    int x = 1;
    vector<int> base6;
    int length = 0;

    reverse(base2.begin(), base2.end());

    for (int i = 0; base2[i]; i++)
    {
        length++;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        deci += ((int)(base2[i]) * x);
        x *= 2;
    }

    int rem = 0;
    while (deci > 0)
    {
        rem = deci % 6;
        base6.push_back(rem);
        deci /= 6;
    }

    reverse(base6.begin(), base6.end());

    return base6;
}

vector<int> main()
{
    vector<bool> base2 = {false, false, true, true};

    return base2To6Hire2020(base2);
}