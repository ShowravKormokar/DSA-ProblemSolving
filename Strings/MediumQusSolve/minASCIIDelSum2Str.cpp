// Leetcode problem 712 -> Minimum ASCII Delete Sum for Two Strings
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        // dp[i][j] = minimum ASCII delete sum
        // to make s1[0..i-1] and s2[0..j-1] equal
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: delete all chars from s1
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        // Base case: delete all chars from s2
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        // Fill DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1], // delete from s1
                        dp[i][j - 1] + s2[j - 1]  // delete from s2
                    );
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    string s1 = "sea", s2 = "eat";

    cout << "Result: " << sol.minimumDeleteSum(s1, s2) << endl;

    return 0;
}