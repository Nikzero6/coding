#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{

    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
        ump[arr[i]]++;

    int count = 0;
    for (auto it = ump.begin(); it != ump.end(); it++)
    {

        int key = k - it->first;

        if (it->first == key)
            count += ((it->second * (it->second - 1)) / 2);

        else
        {
            auto it2 = ump.find(key);

            if (it2 != ump.end())
            {
                count += (it2->second * it->second);
                it2->second = 0;
                it->second = 0;
            }
        }
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << getPairsCount(a, n, k);

    return 0;
}