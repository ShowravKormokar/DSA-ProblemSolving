// Leetcode problem 799 -> Champagne Tower
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));

        dp[0][0] = poured;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] > 1.0)
                {
                    double extra = (dp[i][j] - 1.0) / 2.0;
                    dp[i + 1][j] += extra;
                    dp[i + 1][j + 1] += extra;
                    dp[i][j] = 1.0; // cap at 1
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};

int main()
{
    Solution sol;
    int poured = 1;
    int query_row = 1;
    int query_glass = 1;

    double result = sol.champagneTower(poured, query_row, query_glass);
    cout << "Amount of champagne in the glass at row " << query_row
         << " and glass " << query_glass << ": " << result << endl; // Output: 0.00000

    return 0;
}

/*
TC: O(n^2) where n is the number of rows (100 in this case)
SC: O(n^2) for the dp array
*/