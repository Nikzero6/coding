#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l / 2 + (h - l) / 2];

    int i = l, j = h;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= j)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    arr[j] = pivot;
    return j;
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(arr, l, h);
        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // quicksort(a, 0, 5);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}