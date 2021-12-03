#include <bits/stdc++.h>
using namespace std;
#define N 100000

int minSteps(int a[], int n, int i)
{
    int j = 1;
    static int H[N] = {0};

    if (i == n - 1)
    {
        return 0;
    }
    else if (a[i] + i >= n - 1)
    {
        return 1;
    }
    else if (a[i] == 0)
    {
        return INT_MAX - 1;
    }

    int steps = INT_MAX;

    while (j <= a[i])
    {
        if (H[i + j] == 0)
        {
            int ans = minSteps(a, n, i + j);
            H[i + j] = ans;
            steps = min(steps, ans + 1);
        }
        else
        {
            steps = min(steps, H[i + j] + 1);
        }
        j++;
    }

    return steps;
}
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << minSteps(a, n, 0);

    return 0;
}