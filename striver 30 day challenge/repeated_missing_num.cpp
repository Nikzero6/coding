#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{

#define ll long long
    vector<int> ans(2);
    map<ll, ll> map;

    for (auto elem : A)
    {
        map[elem]++;
    }
    auto it = map.end()--;
    ans[0] = (int)(it->first);

    for (auto it = map.begin(); it != map.end(); it++)
    {
        ll current = it->first;
        it--;
        ll previous = it->first;

        ll gap = current - previous;

        if (gap > 1)
            ans[1] = (int)(current - 1);
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << repeatedNumber(A)[0] << " " << repeatedNumber(A)[1];

    return 0;
}