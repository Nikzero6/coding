#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
    int temp = nums1[i];
    nums1[i] = nums2[j];
    nums2[j] = temp;
}
int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    else
    {
        return (gap / 2) + (gap % 2);
    }
}

void merge(vector<int> &nums1, int m, vector<int> nums2, int n)
{
    int gap = nextGap(m + n);

    while (gap > 0)
    {
        int i = 0;
        int j = i + gap;

        while (j < (m + n))
        {
            if (j < m && nums1[i] > nums1[j])
            {
                swap(nums1, nums1, i, j);
            }
            else if (i < m && j >= m && nums1[i] > nums2[j - m])
            {
                swap(nums1, nums2, i, j - m);
            }
            else if (i >= m && j >= m && nums2[i - m] > nums2[j - m])
            {
                swap(nums2, nums2, i - m, j - m);
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }

    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n), nums2(n);

    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    for (auto elem : nums1)
        cout << elem << " ";

    return 0;
}