// Leetcode problem 1784 -> Check if Binary String Has at Most One Segment of Ones
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        return s.find("01") == string::npos;
    }
};

int main()
{
    Solution sol;
    string s = "1001";
    cout << sol.checkOnesSegment(s) << endl; // Output: false
    return 0;
}

/*
TC: O(n) where n is the length of the input string s, since we need to scan through the string to find the substring "01".
SC: O(1) since we are using a constant amount of extra space to store the result of the find operation and the input string is not modified.
*/