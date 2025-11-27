// Leetcode problem 3381 -> Maximum Subarray Sum With Length Divisible by K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(std::vector<int> &nums, int k)
    {
        long ans = LONG_MIN;
        long prefix = 0;
        // minPrefix[i % k] := the minimum prefix sum of the first i numbers
        vector<long> minPrefix(k, LONG_MAX / 2);
        minPrefix[k - 1] = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefix += nums[i];
            ans = max(ans, prefix - minPrefix[i % k]);
            minPrefix[i % k] = min(minPrefix[i % k], prefix);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    long long result = sol.maxSubarraySum(nums, k);
    cout << "Maximum subarray sum with length divisible by " << k << " is: " << result << endl;
    // Expected output: 9 (subarray [4, 5] or [2, 3, 4] or [1, 2, 3, 4, 5])
    return 0;
}

/*
TC: O(n)
SC: O(k)
*/