// Leetcode probelm 2770 -> Maximum Number of Jumps to Reach the Last Index
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        const int n = nums.size();
        // dp[i] := the maximum number of jumps to reach i from 0
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int j = 1; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 6, 10, 15};
    int target = 4;
    cout << sol.maximumJumps(nums, target) << endl; // Output: 3
    return 0;
}

/*
TC: O(n^2) where n is the size of the input array nums. We have two nested loops, each iterating up to n.
SC: O(n) for the dp array that stores the maximum number of jumps to reach each index.
*/