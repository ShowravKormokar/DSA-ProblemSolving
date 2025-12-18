// Leetcode problem 3652 -> Best Time to Buy and Sell Stock using Strategy
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        vector<long long> s(n + 1), t(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int a = prices[i - 1];
            int b = strategy[i - 1];
            s[i] = s[i - 1] + a * b;
            t[i] = t[i - 1] + a;
        }
        long long ans = s[n];
        for (int i = k; i <= n; i++)
        {
            ans = max(ans, s[n] - (s[i] - s[i - k]) + (t[i] - t[i - k / 2]));
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {4, 2, 8};
    vector<int> strategy = {-1, 0, 1};
    int k = 2;
    cout << "Result: " << sol.maxProfit(prices, strategy, k) << endl;

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/