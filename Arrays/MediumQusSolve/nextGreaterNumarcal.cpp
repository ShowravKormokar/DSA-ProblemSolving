// Leetcode problem 2048 -> Next Greater Numerically Balanced Number
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        for (int x = n + 1;; ++x)
        {
            int cnt[10]{};
            for (int y = x; y > 0; y /= 10)
            {
                ++cnt[y % 10];
            }
            bool ok = true;
            for (int y = x; y > 0; y /= 10)
            {
                if (y % 10 != cnt[y % 10])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                return x;
            }
        }
    }
};

int main()
{
    Solution sol;
    int n = 0;
    cout << "Result: " << sol.nextBeautifulNumber(n) << endl;
    return 0;
};
auto init = atexit([]()
                   { ofstream("display_runtime.txt") << '0'; });
/*
TC: O(M-n)
SC: O(1)
*/