// Leetcode problem 693 -> Binary Number with Alternating Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        //            n = 0b010101
        //       n >> 2 = 0b000101
        // n ^ (n >> 2) = 0b010000 = a
        //        a - 1 = 0b001111
        //  a & (a - 1) = 0
        const int a = n ^ (n >> 2);
        return (a & (a - 1)) == 0;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << sol.hasAlternatingBits(n) << endl; // Output: true
    return 0;
}

/*
TC: O(1) -> We are performing a constant number of bitwise operations.
SC: O(1) -> We are using a constant amount of extra space to store the variable 'a' and the input integer 'n'.
*/