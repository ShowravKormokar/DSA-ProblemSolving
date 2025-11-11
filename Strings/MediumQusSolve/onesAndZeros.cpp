// Leetcode problem 474 -> Ones and Zeroes
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs)
        {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            for (int i = m; i >= zeros; --i)
            {
                for (int j = n; j >= ones; --j)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"10", "0", "1"};
    int m = 1, n = 1;
    cout << sol.findMaxForm(strs, m, n) << endl; // Output: 2
    return 0;
}

/*
TC: O(L * m * n) where L is the number of strings in the input array strs, m is the maximum number of 0's, and n is the maximum number of 1's.
SC: O(m * n) for the dp array.
*/