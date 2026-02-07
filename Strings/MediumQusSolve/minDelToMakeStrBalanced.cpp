// Leetcode problem 1653 -> Minimum Deletions to Make String Balanced
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int i = 0;
        int j = 0;

        for (char c : s)
        {
            if (c == 'a')
                i = min(i + 1, j);
            else
                ++j;
        }
        return i;
    }
};

int main()
{
    Solution sol;
    string s = "aababbab";
    cout << sol.minimumDeletions(s) << endl;
    return 0;
}

/*
TC: O(n) -> where n is the length of the string s
SC: O(1) -> as we are using only constant space to store the count of characters 'a' and 'b'
*/