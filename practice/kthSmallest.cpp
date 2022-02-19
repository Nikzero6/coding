#include <bits/stdc++.h>
#include <math.h>
#include <time.h>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int i = l;
    int j = r;
    int pivot = arr[r];

    while (i < j)
    {
        while (arr[i] < pivot && i < r)
            i++;
        while (arr[j] >= pivot)
            j--;
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, i, r);
    return i;
}

int randomizedPartition(int arr[], int l, int r)
{
    srand(time(0));
    int pivot = (rand() % (r - l + 1)) + l;
    swap(arr, pivot, r);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (l < r)
    {
        int pivot = randomizedPartition(arr, l, r);
        if (pivot == k - 1)
        {
            return arr[pivot];
        }
        else if (pivot > k - 1)
        {
            return kthSmallest(arr, l, pivot - 1, k);
        }
        else
        {
            return kthSmallest(arr, pivot + 1, r, k);
        }
    }

    if (l == r && l == k - 1)
    {
        return arr[l];
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << kthSmallest(a, 0, n - 1, 3);

    return 0;
}