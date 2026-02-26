// Leetcode problem 1404 -> Number of Steps to Reduce a Number in Binary Representation to One
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--)
        {
            int bit = (s[i] - '0') + carry;

            if (bit == 1)
            {
                // odd
                steps += 2;
                carry = 1;
            }
            else
            {
                // even
                steps += 1;
            }
        }

        return steps + carry;
    }
};

int main()
{
    Solution sol;
    string s = "1101";
    cout << sol.numSteps(s) << endl; // Output: 6
    return 0;
}

/*
TC: O(n) where n is the length of the binary string.
SC: O(1) as we are using only a constant amount of extra space.
*/