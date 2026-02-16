// Leetcode problem 190 -> Reverse Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        for (int i = 0; i < 32; ++i)
        {
            if (n >> i & 1)
            {
                ans |= 1 << 31 - i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    uint32_t n = 43261596;
    cout << sol.reverseBits(n) << endl; // Output: 964176192
    return 0;
}

/*
TC: O(1) -> We are always iterating through 32 bits, so the time complexity is constant.
SC: O(1) -> We are using a constant amount of space to store the result and perform the bit manipulation, so the space complexity is also constant.
*/