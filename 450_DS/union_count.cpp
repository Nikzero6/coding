#include <iostream>
using namespace std;
#define N 100000

int doUnion(int a[], int n, int b[], int m)
{

    int H[N] = {0};

    for (int i = 0; i < n; i++)
        H[a[i]]++;

    for (int i = 0; i < m; i++)
        H[b[i]]++;

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (H[i] > 0)
            count++;
    }

    return (count);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << doUnion(a, n, b, m);

    return 0;
}