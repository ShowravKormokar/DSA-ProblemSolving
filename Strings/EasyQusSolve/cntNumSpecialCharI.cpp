// Leetcode problem 3120 -> Count the Number of Special Characters I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int ans = 0;
        vector<bool> lower(26);
        vector<bool> upper(26);

        for (const char c : word)
        {
            if (islower(c))
                lower[c - 'a'] = true;
            else
                upper[c - 'A'] = true;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (lower[i] && upper[i])
                ++ans;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string word = "aAAbbbb";
    cout << sol.numberOfSpecialChars(word) << endl; // Output: 1
    return 0;
}

/*
TC: O(n) where n is the length of the input string `word`.
SC: O(1) since we are using fixed-size boolean arrays to track the presence of lowercase and uppercase characters, which does not depend on the input size.
*/