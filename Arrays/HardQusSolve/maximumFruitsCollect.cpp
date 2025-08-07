// Leetcode problem 3363 -> Find the maximum number of fruits collected

/*

---------------- This is very complex problem need more study to proper understanding.❌☠️

*/

#include <bits/stdc++.h>
using namespace std;

int maxCollectedFruits(vector<vector<int>> &fruits)
{
    return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) -
           2 * fruits.back().back();
}

int getTopLeft(const vector<vector<int>> &fruits)
{
    const int n = fruits.size();
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += fruits[i][i];
    return res;
}

int getTopRight(const vector<vector<int>> &fruits)
{
    const int n = fruits.size();
    // dp[i][j] := the number of fruits collected from (0, n - 1) to (i, j)
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][n - 1] = fruits[0][n - 1];
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            if (x >= y && !(x == n - 1 && y == n - 1))
                continue;
            for (const auto &[dx, dy] :
                 vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}})
            {
                const int i = x - dx;
                const int j = y - dy;
                if (i < 0 || i == n || j < 0 || j == n)
                    continue;
                if (i < j && j < n - 1 - i)
                    continue;
                dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
            }
        }
    }

    return dp[n - 1][n - 1];
}

int getBottomLeft(const vector<vector<int>> &fruits)
{
    const int n = fruits.size();
    // dp[i][j] := the number of fruits collected from (n - 1, 0) to (i, j)
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][0] = fruits[n - 1][0];
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (x <= y && !(x == n - 1 && y == n - 1))
                continue;
            for (const auto &[dx, dy] :
                 vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}})
            {
                const int i = x - dx;
                const int j = y - dy;
                if (i < 0 || i == n || j < 0 || j == n)
                    continue;
                if (j < i && i < n - 1 - j)
                    continue;
                dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main()
{
    vector<vector<int>> fruits = {
        {1, 2, 3, 4},
        {5, 6, 8, 7},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    cout << "Maximum fruits collected: " << maxCollectedFruits(fruits) << endl; // Output: error🚨
    return 0;
}