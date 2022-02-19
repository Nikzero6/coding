#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(int i, int n, int a[], vector<int> &ds)
{
    if (i == n)
    {
        if (ds.size() == 0)
            cout << "{}";

        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;

        return;
    }

    // take given index element in subsequence
    ds.push_back(a[i]);
    printSubsequences(i + 1, n, a, ds);
    ds.pop_back();

    // do not take given index element in subsequence
    printSubsequences(++i, n, a, ds);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ds;

    printSubsequences(0, n, a, ds);

    return 0;
}