#include <iostream>
#include <vector>
using namespace std;

void f(int i, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums)
{
    if (nums.size() == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        ds.push_back(nums[i]);
        nums.erase(nums.begin() + i);
        f(i + 1, ds, ans, nums);
        nums.insert(nums.begin() + i, ds.back());
        ds.pop_back();
    }

    return;
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<int> ds;
    vector<vector<int>> ans;

    f(0, ds, ans, nums);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = permute(nums);

    for (auto it : ans)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}