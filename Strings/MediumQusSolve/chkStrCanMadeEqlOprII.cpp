// Leetcode problem 2840 -> Check if Strings Can be Made Equal With Operations II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        vector<vector<int>> count(2, vector<int>(26));

        for (int i = 0; i < s1.length(); ++i)
        {
            ++count[i % 2][s1[i] - 'a'];
            --count[i % 2][s2[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i)
            if (count[0][i] > 0 || count[1][i] > 0)
                return false;

        return true;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcd", s2 = "cdab";
    cout << sol.checkStrings(s1, s2) << endl; // Output: true
    return 0;
}

/*
TC: O(n) where n is the length of the input strings s1 and s2.
SC: O(1) since we are using a fixed-size 2D vector of size 2x26 to count the frequency of characters at even and odd indices.
*/