// Leetcode problem 3186 -> Maximum total damage with spell casting
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<int, long long> cnt;
        for (int x : power)
        {
            cnt[x]++;
        }
        // Collect unique damage values
        vector<int> uniq;
        uniq.reserve(cnt.size());
        for (auto &kv : cnt)
        {
            uniq.push_back(kv.first);
        }
        sort(uniq.begin(), uniq.end());
        int m = uniq.size();
        // nxt[i] = smallest j > i such that uniq[j] > uniq[i] + 2
        vector<int> nxt(m);
        for (int i = 0; i < m; i++)
        {
            long long v = uniq[i];
            // we want first index j with uniq[j] > v + 2
            int j = upper_bound(uniq.begin() + i + 1, uniq.end(), v + 2) - uniq.begin();
            nxt[i] = j;
        }
        // dp[i] = maximum damage we can get starting from index i (onwards)
        vector<long long> dp(m + 1, 0);
        // dp[m] = 0 by default
        // Iterate backwards
        for (int i = m - 1; i >= 0; i--)
        {
            // option skip
            long long skip = dp[i + 1];
            // option take
            long long take = cnt[uniq[i]] * uniq[i];
            if (nxt[i] <= m)
            {
                take += dp[nxt[i]];
            }
            dp[i] = max(skip, take);
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    vector<int> power = {1, 1, 3, 4};
    cout << "Maximum damage: " << sol.maximumTotalDamage(power) << endl;
    return 0;
}