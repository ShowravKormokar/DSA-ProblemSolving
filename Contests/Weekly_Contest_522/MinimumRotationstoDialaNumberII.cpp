//  Minimum Rotations to Dial a Number II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRotations(int n, string s)
    {
        auto digit = [](char c)
        { return c - '0'; };
        auto circDist = [](int a, int b)
        {
            int diff = abs(a - b);
            return min(diff, 10 - diff);
        };

        vector<long long> P(n, 0);
        for (int i = 1; i < n; i++)
        {
            P[i] = P[i - 1] + circDist(digit(s[i - 1]), digit(s[i]));
        }

        long long totalD = (n >= 1) ? P[n - 1] : 0;
        long long startCost = circDist(0, digit(s[0]));

        long long best = LLONG_MAX;

        best = min(best, circDist(0, digit(s[n - 1])) + totalD);

        for (int k = 1; k < n; k++)
        {
            long long cost = startCost + P[k - 1] + circDist(digit(s[k - 1]), digit(s[n - 1])) + (totalD - P[k]);
            best = min(best, cost);
        }

        return (int)best;
    }
};

int main()
{
    Solution sol;
    int n;
    string s;
    cin >> n >> s;
    cout << sol.minRotations(n, s) << endl;
    return 0;
}