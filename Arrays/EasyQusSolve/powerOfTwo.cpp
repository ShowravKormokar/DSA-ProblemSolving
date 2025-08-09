// Leetcode problem 231 -> Power of two
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    // Way 1
    if (n > 0 && (n & (n - 1)))
    {
        return false;
    }
    else
    {
        return n > 0;
    }
    // Way 2
    // return n >= 0 && __builtin_popcount(n) == 1;
}

int main()
{
    int n = 16;
    cout << "Is power of two: " << isPowerOfTwo(n) << endl;
    return 0;
}