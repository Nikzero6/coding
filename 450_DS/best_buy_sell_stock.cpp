#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int merge(vector<int> &prices, int l, int mid, int h)
{
    int m = mid - l + 1;
    int n = h - mid;

    int left[m], right[n];

    for (int i = 0; i < m; i++)
        left[i] = prices[l + i];

    for (int i = 0; i < n; i++)
        right[i] = prices[mid + i + 1];

    int i = 0, j = 0, k = l;
    while (i < m && j < n)
    {
        if (left[i] < right[j])
        {
            prices[k++] = left[i++];
        }

        else if (left[i] > right[j])
            prices[k++] = right[j++];

        else
        {
            prices[k++] = left[i++];
            prices[k++] = right[j++];
        }
    }

    while (i < m)
        prices[k++] = left[i++];

    while (j < n)
        prices[k++] = right[j++];

    if (left[0] < right[n - 1])
        return (right[n - 1] - left[0]);
    else
        return 0;
}
int merge_sort(vector<int> &prices, int l, int h)
{
    if (l == h)
        return 0;

    int mid = l + (h - l) / 2;
    merge_sort(prices, l, mid);
    merge_sort(prices, mid + 1, h);
    ans = max(ans, merge(prices, l, mid, h));

    return ans;
}
int dp_approach(vector<int> prices)
{
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        min_price = min(min_price, prices[i]);

        max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
}
int main()
{

    vector<int> prices;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        prices.push_back(elem);
    }

    int ans = dp_approach(prices);

    cout << ans;

    return 0;
}