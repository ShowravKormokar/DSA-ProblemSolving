// Leetcode problem 868 -> Binary Gap
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int last = -1; // to store the position of the last seen 1 bit
        int maxGap = 0;
        int pos = 0; // present bit position

        while (n > 0)
        {
            if (n & 1)
            { // if the last bit is 1
                if (last != -1)
                {
                    maxGap = max(maxGap, pos - last);
                }
                last = pos;
            }

            n >>= 1; // right shift
            pos++;
        }

        return maxGap;
    }
};

int main()
{
    Solution sol;
    int n = 22;
    cout << "The binary gap for " << n << " is: " << sol.binaryGap(n) << endl; // Output: 2
    return 0;
}

/*
TC: O(log n) - We are iterating through the bits of the number, which takes logarithmic time in relation to the value of n.
SC: O(1) - We are using a constant amount of extra space to store the last seen position of a 1 bit and the maximum gap.
*/