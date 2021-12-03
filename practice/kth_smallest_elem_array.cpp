/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];

    int i = l, j = h;

    while (i < j)
    {
        while (arr[i] <= pivot & i < h)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, l);
    return j;
}

int randPartition(int arr[], int l, int h)
{
    srand(time(0));
    int r = (rand() % (h - l + 1)) + l;

    swap(arr, l, r);

    return partition(arr, l, h);
}

int kthSmallest(int arr[], int l, int r, int k)
{

    if (l < r)
    {
        int pivot = randPartition(arr, l, r);

        if (pivot == k - 1)
            return arr[k - 1];
        else if (pivot < k - 1)
            return kthSmallest(arr, pivot + 1, r, k);
        else
            return kthSmallest(arr, l, pivot - 1, k);
    }
    else if (l == r)
        return arr[l];

    return -1;
}
int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    cout << kthSmallest(a, 0, n - 1, k);

    return 0;
}
