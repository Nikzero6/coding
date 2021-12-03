#include <iostream>
using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void insert(int a[], int j, int i)
{
    int temp = a[i];
    for (i; i < j; i++)
    {
        a[i] = a[i + 1];
    }
    a[j] = temp;
}
void segNegPos(int a[], int n)
{
    int i = 0, j = 0;

    while (j < n && i < n)
    {
        if (i == j && a[i] < 0)
        {
            i++;
            j++;
        }
        else if (a[i] > 0)
        {
            int temp = j;

            while (a[j] > 0 && j < n)
                j++;

            if (a[j] < 0 && j < n)
            {
                swap(a, i, j);
                i++;
            }
            else
            {
                insert(a, temp, i);
            }
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    segNegPos(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}