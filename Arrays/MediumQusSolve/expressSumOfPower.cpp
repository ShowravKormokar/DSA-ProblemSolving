// Leetcode problem 2787 -> Ways to express an integer as sum of power
#include <bits/stdc++.h>
using namespace std;

int numberOfWays(int n, int x)
{
    constexpr int kMod = 1000000007;
    vector<int> dp(n + 1);
    int ax;

    dp[0] = 1;

    for (int a = 1; (ax = pow(a, x)) <= n; ++a)
        for (int i = n; i >= ax; --i)
        {
            dp[i] += dp[i - ax];
            dp[i] %= kMod;
        }

    return dp[n];
}

int main()
{
    int n = 10, x = 2;
    cout << "Number of ways: " << numberOfWays(n, x) << endl; // Output: 1
    return 0;
}

/*
TC: O(nlogn)
SC: O(n)
*/