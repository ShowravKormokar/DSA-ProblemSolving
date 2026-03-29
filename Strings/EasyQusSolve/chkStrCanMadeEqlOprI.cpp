// Leetcode problem 2839 -> Check if Strings Can be Made Equal With Operations I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        for (const string &a : swappedStrings(s1))
            for (const string &b : swappedStrings(s2))
                if (a == b)
                    return true;
        return false;
    }

private:
    vector<string> swappedStrings(const string &s)
    {
        vector<char> chars(s.begin(), s.end());
        return {s, string({chars[2], chars[1], chars[0], chars[3]}),
                string({chars[0], chars[3], chars[2], chars[1]}),
                string({chars[2], chars[3], chars[0], chars[1]})};
    }
};

int main()
{
    Solution sol;
    string s1 = "abcd", s2 = "cdab";
    cout << sol.canBeEqual(s1, s2) << endl; // Output: true
    return 0;
}

/*
TC: O(1) - The number of operations is constant since we are only generating a fixed number of permutations (4 in this case).
SC: O(1) - We are using a constant amount of extra space to store the swapped strings, and the input strings are not modified in place.
*/