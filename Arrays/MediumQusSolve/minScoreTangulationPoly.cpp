// Leetcode problem 1039 -> Minimum Score Triangulation of Polygon
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // dp[i][j] = minimum score to triangulate polygon between vertex i and j
        for (int len = 2; len < n; len++)
        {
            for (int i = 0; i + len < n; i++)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> values = {1, 2, 3};
    cout << "Minimum Score Triangulation = "
         << sol.minScoreTriangulation(values) << endl; // Output: 6
    return 0;
}

/*
TC: O(n^3)
SC: O(n^2)
*/