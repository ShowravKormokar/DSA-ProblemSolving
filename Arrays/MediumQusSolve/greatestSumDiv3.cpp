// Leetcode problem -> 1262. Greatest Sum Divisible by Three
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> dp(3); // dp[i] := the maximum sum so far s.t. sum % 3 == i

        for (const int num : nums)
            for (const int sum : vector<int>(dp))
                dp[(sum + num) % 3] = max(dp[(sum + num) % 3], sum + num);

        return dp[0];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 6, 5, 1, 8};
    cout << sol.maxSumDivThree(nums) << endl; // Output: 18
    return 0;
}

//

/*
TC: O(N) where N is the number of elements in the nums array.
SC: O(1) since we are using a fixed-size array of size 3 for the dp array.
This solution efficiently calculates the maximum sum of elements in nums that is divisible by 3.
*/