// Leetcode problem 1611 -> Minimum One Bit Operations to Make Integers Zero
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n == 0)
            return 0;
        int x = 1;
        while (x * 2 <= n)
            x <<= 1;
        return minimumOneBitOperations(n ^ (x | x >> 1)) + 1 + x - 1;
    }
};
int main()
{
    Solution sol;
    int n = 6; // Example input
    cout << "Minimum One Bit Operations to Make " << n << " Zero: " << sol.minimumOneBitOperations(n) << endl; // Output: 9
    return 0;
}

/*
TC: O(log n)
SC: O(1)
*/