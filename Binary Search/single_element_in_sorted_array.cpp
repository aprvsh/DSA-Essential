#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (nums[mid] != nums[mid + 1] || nums[mid] != nums[mid - 1])
            {
                return nums[mid];
            }
            else if (nums[mid] == nums[mid - 1])
            {
                end = mid - 1;
            }
            else if (nums[mid] == nums[mid + 1])
            {
                start = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (nums[mid] != nums[mid + 1])
                return mid;
        }
        else if (mid == n - 1)
        {
            if (nums[mid] != nums[mid - 1])
                return mid;
        }
    }
}