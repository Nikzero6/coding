#include <iostream>
using namespace std;

//devide and conquer
//for even 3(n/2)-2 comparisons for odd 3(n-1)/2 comparisons

int *maxmin(int *a, int n)
{
    int *p = new int[2];
    int i = 0;

    if (n % 2 == 0)
    {

        if (a[0] > a[1])
        {
            p[0] = a[0];
            p[1] = a[1];
        }
        else
        {
            p[0] = a[1];
            p[1] = a[0];
        }

        i = 2;
    }
    else
    {
        p[0] = a[0];
        p[1] = a[1];

        i = 1;
    }

    while (i < n - 1)
    {

        if (a[i] < a[i + 1])
        {
            p[0] = max(p[0], a[i + 1]);
            p[1] = min(p[1], a[i]);
        }
        else
        {
            p[0] = max(p[0], a[i]);
            p[1] = min(p[1], a[i + 1]);
        }

        i += 2;
    }

    return p;
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

    cout << "max: " << maxmin(a, n)[0] << " min: " << maxmin(a, n)[1] << endl;
}