#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int binarySearch(vector<int> &nums, int l, int h, int key)
{
    int ans = INT_MAX;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (nums[mid] > key)
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else if (nums[mid] <= key)
        {
            l = mid + 1;
        }
    }

    if (ans == INT_MAX)
        return 0;
    else
        return ans;
}
void next_perm(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--)
    {
        int idx = binarySearch(nums, i + 1, n - 1, nums[i]);

        if (idx)
        {
            swap(nums, i, idx);
            break;
        }
        else
            sort(nums.begin() + i, nums.end());
    }
}

void next_perm_reverse(vector<int> &nums)
{
    int n = nums.size();

    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0)
    {
        int j = i;
        while (j < n - 1 && nums[i] < nums[j + 1])
            j++;

        swap(nums, i, j);
    }
    int start = (i + 1);

    reverse(nums.begin() + start, nums.end());
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    next_perm_reverse(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    return 0;
}