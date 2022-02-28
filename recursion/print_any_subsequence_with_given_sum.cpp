#include <iostream>
#include <vector>
using namespace std;

bool printSubSequence(int i, int n, int a[], vector<int> ds, int sum, int curr_sum)
{
    if (i == n)
    {
        if (curr_sum == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;

            return true;
        }
        return false;
    }

    ds.push_back(a[i]);
    if (printSubSequence(i + 1, n, a, ds, sum, curr_sum + a[i]) == true)
        return true;

    ds.pop_back();

    if (printSubSequence(i + 1, n, a, ds, sum, curr_sum) == true)
        return true;

    return false;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ds;
    int sum;
    cin >> sum;
    printSubSequence(0, n, a, ds, sum, 0);

    return 0;
}