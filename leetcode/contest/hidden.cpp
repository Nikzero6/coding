#include <bits/stdc++.h>
using namespace std;

int numberOfArrays(vector<int> &differences, int lower, int upper)
{
    int count = 0;
    int n = differences.size();

    if (n == 0)
        return 0;

    for (int i = lower; i <= upper; i++)
    {
        int j = 0;

        int current = i + differences[j];
        while (j < n && current <= upper && current >= lower)
        {
            j++;
            if (n == 1 || j == n)
                continue;
            current += differences[j];
        }

        if (j == n)
            count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l, u;
    cin >> l >> u;
    cout << numberOfArrays(a, l, u);

    return 0;
}
