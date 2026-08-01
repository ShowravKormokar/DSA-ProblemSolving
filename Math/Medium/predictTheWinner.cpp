// Leetcode problem 486 -> Predict the Winner
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        const int n = nums.size();
        // dp[i][j] := the maximum number you can get more than your opponent in
        // nums[i..j]
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];

        for (int d = 1; d < n; ++d)
            for (int i = 0; i + d < n; ++i)
            {
                const int j = i + d;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }

        return dp[0][n - 1] >= 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 5, 2};
    bool result = solution.PredictTheWinner(nums);
    cout << "Can player 1 win? " << (result ? "Yes" : "No") << endl;
    return 0;
}

/*
TC: O(n^2) where n is the length of the nums array
SC: O(n^2) for the dp array
*/