#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        maxSum = max(maxSum, sum);
        if (sum <= 0)
            sum = 0;
    }

    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maxSubarray(nums);

    return 0;
}