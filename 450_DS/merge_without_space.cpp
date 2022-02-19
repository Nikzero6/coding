#include <iostream>
#include <math.h>
using namespace std;

void rightShift(int a[], int i, int n)
{
    for (int j = n - 1; j > i; j--)
    {
        a[j] = a[j - 1];
    }
}
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void merge_my_method(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    int stop = 0;
    if (n > m)
    {
        stop = n - 1;
    }
    else
    {
        stop = n;
    }

    while (i < stop)
    { // 3<3                  //{0, 1, 2, 3}     i=3, j=2, k=1
        //{4, 5, 7, 8, 9}
        int k = 0;

        while (k < 1 && i < n)
        {
            if (arr1[i] > arr2[k])
            {                           // 3>2
                int last = arr1[n - 1]; // 5
                rightShift(arr1, i, n);
                arr1[i] = arr2[k]; // 2
                arr2[k] = last;    // 5
                k++;
            }
            i++;
        }

        j = 0;

        while (arr2[j] > arr2[j + 1])
        { // 2>6
            swap(arr2, j, j + 1);
            j++;
        }
    }
}

void merge_last_swapping(int arr1[], int arr2[], int n, int m)
{

    for (int i = m - 1; i >= 0; i--)
    {

        int last = arr1[n - 1];

        int j = n - 2;

        while (arr2[i] < arr1[j] && j >= 0)
        {
            arr1[j + 1] = arr1[j];
            j--;
        }

        if (j != n - 2)
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
        else if (arr1[n - 1] > arr2[i])
        {
            arr1[n - 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

void merge_gap(int arr1[], int arr2[], int n, int m)
{
    int N = m + n;
    int gap = nextGap(N);

    while (gap > 0)
    {
        int l = 0;
        int h = l + gap;

        while (h < N)
        {

            if (l < n && h < n && arr1[l] > arr1[h])
            {
                int temp = arr1[h];
                arr1[h] = arr1[l];
                arr1[l] = temp;
            }
            else if (l < n && h > n - 1 && arr1[l] > arr2[h - n])
            {
                int temp = arr2[h - n];
                arr2[h - n] = arr1[l];
                arr1[l] = temp;
            }
            else if (l > n && h > n && arr2[l - n] > arr2[h - n])
            {
                int temp = arr2[h - n];
                arr2[h - n] = arr2[l - n];
                arr2[l - n] = temp;
            }

            l++;
            h++;
        }

        gap = nextGap(gap);
    }
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    merge_gap(a, b, n, m);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";

    return 0;
}