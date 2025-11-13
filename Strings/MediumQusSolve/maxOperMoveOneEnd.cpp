// Leetcode problem 3228 -> Maximum Number of Operations to Move Ones to the End
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int ans = 0;
        int ones = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '1')
                ++ones;
            else if (i + 1 == s.length() || s[i + 1] == '1')
                ans += ones;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "1001101";
    cout << sol.maxOperations(s) << endl; // Output: 8
    return 0;
}

/*
TC: O(n) where n is the length of the string s.
SC: O(1) as we are using only a constant amount of extra space.
*/