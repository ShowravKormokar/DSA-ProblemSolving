// Leetcode problem 1513 -> Number of Substrings With Only 1s
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSub(string s)
    {
        constexpr int kMod = 1'000'000'007;

        int ans = 0;
        int l = -1;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0')
                l = i; // Handle the reset value.
            ans = (ans + i - l) % kMod;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "110100110";
    cout << sol.numSub(s) << endl; // Example usage
    return 0;
}

/*
TC: O(n), where n is the length of the input string s.
SC: O(1).
*/