#include <bits/stdc++.h>
using namespace std;
#define int long long int

int binarySearch(int arr[], int l, int h, int key)
{
    int ans = INT_MIN;
    int org_l = l;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] < key)
        {
            ans = max(mid, ans);
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    if (ans != INT_MIN)
        return ans - org_l + 1;
    else
        return 0;
}
int inversionCount(int arr[], int n)
{
    int i = n - 2;
    int count = 0;

    while (i >= 0)
    {
        count += binarySearch(arr, i + 1, n - 1, arr[i]);

        sort(arr + i, arr + n);

        i--;
    }

    return count;
}
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int merge_cus(int arr[], int l, int mid, int h)
{
    int count = 0;

    int m = mid - l + 1;
    int n = h - mid;

    int left_arr[m], right_arr[n];

    for (int i = 0; i < m; i++)
        left_arr[i] = arr[l + i];

    for (int j = 0; j < n; j++)
        right_arr[j] = arr[mid + j + 1];

    int i = 0, j = 0, k = l;

    while (i < m && j < n)
    {
        if (left_arr[i] <= right_arr[j])
            arr[k++] = left_arr[i++];
        else
        {
            arr[k++] = right_arr[j++];
            count += (m - i);
        }
    }

    while (i < m)
        arr[k++] = left_arr[i++];

    while (j < n)
        arr[k++] = right_arr[j++];

    return count;
}
int merge_sort(int arr[], int l, int h)
{
    int count = 0;

    if (l < h)
    {
        int mid = l + (h - l) / 2;
        count += merge_sort(arr, l, mid);
        count += merge_sort(arr, mid + 1, h);
        count += merge_cus(arr, l, mid, h);
    }

    return count;
}
int inversion_count_merge(int arr[], int N)
{
    int ans = merge_sort(arr, 0, N - 1);

    return ans;
}
int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << inversion_count_merge(arr, n);

    return 0;
}