#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i;
    for (i = n - 2; i >= 0;)
    {
        if (nums[i] >= nums[i + 1])
            i--;
        else
            break;
    }
    int j;
    for (j = i + 1; j < n - 2;)
    {
        if (nums[j] > nums[i])
            j++;
    }

    swap(nums, i, j-1);

    reverse(nums.begin() + i + 1, nums.end());
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

    nextPermutation(nums);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}