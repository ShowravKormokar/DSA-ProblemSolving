// Leetcode problem 1758 -> Minimum Changes To Make Alternating Binary String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int cur = 0, cnt1 = 0;
        for (char c : s)
        {
            if (c - '0' != cur)
            {
                cnt1++;
            }
            cur ^= 1;
        }

        cur = 1;
        int cnt2 = 0;
        for (char c : s)
        {
            if (c - '0' != cur)
            {
                cnt2++;
            }
            cur ^= 1;
        }

        return min(cnt1, cnt2);
    }
};

int main()
{
    Solution sol;
    string s = "0100";
    cout << sol.minOperations(s) << endl;
    return 0;
}

/*
TC: O(n) where n is the length of the string s.
SC: O(1) since we are using only a constant amount of space to store the cost of making s "1010" and "0101".
*/