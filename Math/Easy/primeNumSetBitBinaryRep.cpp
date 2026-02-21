// Leetcode problem 762 -> Prime Number of Set Bits in Binary Representation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        // {2, 3, 5, 7, 11, 13, 17, 19}-th bits are 1s.
        // 0b10100010100010101100 = 665772
        constexpr int magic = 665772;
        int ans = 0;

        for (unsigned num = left; num <= right; ++num)
            if (magic >> __builtin_popcount(num) & 1)
                ++ans;

        return ans;
    }
};

int main()
{
    Solution sol;
    int left = 6, right = 10;
    cout << sol.countPrimeSetBits(left, right) << endl; // Output: 4
    return 0;
}

/*
TC: O(n), where n is the number of integers in the range [left, right].
SC: O(1), as we are using a constant amount of extra space for the magic number and the answer variable.
*/