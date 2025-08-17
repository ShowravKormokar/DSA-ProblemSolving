// Leetcode problem 837 -> New 21 Game
#include <bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts)
{
    if (k == 0 || n >= k - 1 + maxPts)
        return 1.0;

    double ans = 0.0;
    vector<double> dp(n + 1);
    dp[0] = 1.0;
    double windowSum = dp[0];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = windowSum / maxPts;
        if (i < k)
        {
            windowSum += dp[i];
        }
        else
        {
            ans += dp[i];
        }

        if (i - maxPts >= 0)
        {
            windowSum -= dp[i - maxPts];
        }
    }
    return ans;
}

int main()
{
    int n = 6, k = 1, maxPts = 10;
    cout << "Result: " << new21Game(n, k, maxPts) << endl; // Output: 0.6

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/