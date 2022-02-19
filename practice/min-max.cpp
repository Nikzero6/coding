#include <bits/stdc++.h>
using namespace std;

class Minmax
{
public:
    int minimum, maximum;
    Minmax()
    {
        minimum = INT_MAX;
        maximum = INT_MIN;
    }
    void minmax(int *arr, int length);
};

void Minmax::minmax(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        minimum = min(minimum, arr[i]);
        maximum = max(maximum, arr[i]);
    }
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

    Minmax ans;
    ans.minmax(a, n);
    cout << ans.minimum << " " << ans.maximum;
    return 0;
}