#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxDiff = 0;
    int i = 0, j = 1;
    int n = prices.size();

    while (j <= n - 1)
    {
        if (prices[j] > prices[i])
        {
            maxDiff = max(prices[j] - prices[i], maxDiff);
            j++;
        }
        else
        {
            i = j;
            j++;
        }
    }
    return maxDiff;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}