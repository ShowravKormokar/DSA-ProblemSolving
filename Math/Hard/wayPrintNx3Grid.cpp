// Leetcode problem 1411. Number of Ways to Paint N × 3 Grid
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfWays(int n)
    {
        const int MOD = 1e9 + 7;

        long long a = 6; // ABA
        long long b = 6; // ABC

        for (int i = 2; i <= n; i++)
        {
            long long newA = (a * 3 + b * 2) % MOD;
            long long newB = (a * 2 + b * 2) % MOD;
            a = newA;
            b = newB;
        }

        return (a + b) % MOD;
    }
};

int main()
{
    Solution sol;
    int n = 1;
    cout << "Result: " << sol.numOfWays(n) << endl; 

    return 0;
}

/*
TC: O(N)
SC: O(1)
*/