// Leetcode problem 3754 -> Concatenate Non-Zero Digits and Multiply by Sum I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        int p = 1;
        int x = 0, s = 0;
        for (; n > 0; n /= 10)
        {
            int v = n % 10;
            if (v != 0)
            {
                s += v;
                x += p * v;
                p *= 10;
            }
        }
        return 1LL * x * s;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << sol.sumAndMultiply(n) << endl;
    return 0;
}

/*
TC :O(log n) where n is the input number
SC :O(1)
*/