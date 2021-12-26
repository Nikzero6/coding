#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void sortColors(vector<int> &nums)
{
    int l = 0, mid = 0, h = nums.size() - 1;

    while (mid <= h)
    {
        if (nums[mid] == 0)
        {
            swap(nums, mid, l);
            l++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums, mid, h);
            h--;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sortColors(nums);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}