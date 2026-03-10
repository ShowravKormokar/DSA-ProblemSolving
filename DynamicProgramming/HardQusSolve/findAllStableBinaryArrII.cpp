// Leetcode problem 3130 -> Find All Possible Stable Binary Arrays II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Same as 3129. Find All Possible Stable Binary Arrays I
    int numberOfStableArrays(int zero, int one, int limit)
    {
        constexpr int kMod = 1'000'000'007;
        // dp[i][j][k] := the number of stable arrays, where the number of
        // ocurrences of 0 is i and the number of ocurrences of 1 is j and the last
        // number is k (0/1)
        vector<vector<vector<long>>> dp(
            zero + 1, vector<vector<long>>(one + 1, vector<long>(2)));

        for (int i = 0; i <= min(zero, limit); ++i)
            dp[i][0][0] = 1;

        for (int j = 0; j <= min(one, limit); ++j)
            dp[0][j][1] = 1;

        for (int i = 1; i <= zero; ++i)
            for (int j = 1; j <= one; ++j)
            {
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] -
                               (i - limit < 1 ? 0 : dp[i - limit - 1][j][1]) + kMod) %
                              kMod;
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1] -
                               (j - limit < 1 ? 0 : dp[i][j - limit - 1][0]) + kMod) %
                              kMod;
            }

        return (dp[zero][one][0] + dp[zero][one][1]) % kMod;
    }
};

int main()
{
    Solution sol;
    int zero = 2, one = 1, limit = 1;
    cout << sol.numberOfStableArrays(zero, one, limit) << endl;
    return 0;
}

/*
TC: O(zero * one) -> we have to fill the dp table of size (zero + 1) * (one + 1) * 2
SC: O(zero * one) -> we are using a 3D dp table of  size (zero + 1) * (one + 1) * 2
*/