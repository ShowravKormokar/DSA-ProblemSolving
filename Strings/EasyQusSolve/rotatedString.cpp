// Leetcode problem -> 796 Rotate String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};

int main()
{
    Solution sol;
    string s = "abcde", goal = "cdeab";
    cout << sol.rotateString(s, goal) << endl; // Output: true
    return 0;
}

/*
TC: O(n) where n is the length of the string s (or goal)
SC: O(n) due to the concatenation of string s with itself, which creates a new string of length 2n.
*/