#include <bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> &cost)
{
    sort(cost.begin(), cost.end(), greater<int>());
    int sum = 0;
    int n = cost.size();
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 3 == 0)
            continue;

        sum += cost[i];
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << minimumCost(a);

    return 0;
}
