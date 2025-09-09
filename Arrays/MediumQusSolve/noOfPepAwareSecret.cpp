// Leetcode problem 2327 -> Number of People Aware of a Secret
#include <bits/stdc++.h>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int MOD = 1e9 + 7;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1; // Day 1: one person knows

    long long sharing = 0; // how many can share at a given day

    for (int i = 2; i <= n; i++)
    {
        // people start sharing after delay
        if (i - delay >= 1)
        {
            sharing = (sharing + dp[i - delay]) % MOD;
        }
        // people forget after forget
        if (i - forget >= 1)
        {
            sharing = (sharing - dp[i - forget] + MOD) % MOD;
        }
        dp[i] = sharing; // new people on day i
    }

    // Sum of all people who haven’t forgotten by day n
    long long ans = 0;
    for (int i = n - forget + 1; i <= n; i++)
    {
        if (i >= 1)
            ans = (ans + dp[i]) % MOD;
    }
    return ans;
}

int main()
{
    int n = 6, delay = 2, forget = 4;
    cout << "Result: " << peopleAwareOfSecret(n, delay, forget) << endl;

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/