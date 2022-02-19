#include <iostream>
using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void MoveNegPos(int a[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        while (a[i] < 0 && i < n - 1)
            i++;
        while (a[j] > 0 && j > 0)
            j--;
        if (i < j)
        {
            swap(a, i, j);
        }
    }
}
int main()
{
    //code
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    MoveNegPos(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}