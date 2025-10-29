// Leetcode problem 3370 -> Smallest number with all set of bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {
        return (1 << (32 - __builtin_clz(n))) - 1; // Count number of bit, then convert bynary to decimal then subtract by 1 (Because all bits must 1)
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << "Result: " << sol.smallestNumber(n) << endl; // Output: 7
    return 0;
}

/*
TC: O(log*n)
SC: O(1)
*/