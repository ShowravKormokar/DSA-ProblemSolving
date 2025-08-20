// Leetcode problem 1277 -> Count square submatrices with all ones
#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                ans += dp[i][j];
            } // else dp[i][j] stays 0
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {0, 1, 1, 1}};

    cout << "Results: " << countSquares(matrix) << endl; // Output: 15

    return 0;
}

/*
TC: O(mxn)
SC: O(n)
*/