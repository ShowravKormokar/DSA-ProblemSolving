// Leetcode problem 696 -> Count Binary Substrings
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int currIdx = 0;
        int strLen = s.size();

        vector<int> grpSize;

        while (currIdx < strLen)
        {
            int grpCnt = 1;

            while (currIdx + 1 < strLen && s[currIdx + 1] == s[currIdx])
            {
                ++grpCnt;
                ++currIdx;
            }

            grpSize.push_back(grpCnt);
            ++currIdx;
        }

        int result = 0;

        // FIX: start from 1
        for (int i = 1; i < grpSize.size(); i++)
        {
            result += min(grpSize[i - 1], grpSize[i]);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    string s = "00110011";
    cout << sol.countBinarySubstrings(s) << endl;

    return 0;
}

/*
TC: O(n) -> traverse the string once
SC: O(n) -> in worst case, all characters are different, then we will have n groups of size 1, so the grpSize vector will have n elements
*/