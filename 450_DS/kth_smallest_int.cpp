#include <iostream>
using namespace std;

void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;

    while (i < j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a, i, j);
    }

    swap(a, j, l);

    return j;
}

int quickselect(int *a, int l, int h, int k)
{
    int pivot = partition(a, l, h);

    if (pivot > k - 1)
        return quickselect(a, l, pivot - 1, k);
    else if (pivot < k - 1)
        return quickselect(a, pivot + 1, h, k);
    else
        return a[pivot];
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

    int k;
    cin >> k;

    cout << quickselect(a, 0, n - 1, k) << endl;
    return 0;
}