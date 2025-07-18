// Leetcode 53 problem -> Maximum Subarray
#include <bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int> &nums)
{
    int maxSum = nums[0], sum = 0;
    for (auto num : nums)
    {
        sum += num;
        if (sum > maxSum)
            maxSum = sum;
        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum sum of subarray: " << maximumSubarray(nums) << endl;

    return 0;
}