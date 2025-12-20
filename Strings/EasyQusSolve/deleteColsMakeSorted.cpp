// Leetcode problem 944 -> Delete Columns to Make Sorted
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int cnt = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            string temp = "";
            for (int j = 0; j < strs.size(); j++)
            {
                temp += strs[j][i];
            }
            string t2 = temp;
            sort(t2.begin(), t2.end());
            if (temp != t2)
                cnt++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"rrjk", "furt", "guzm"};
    cout << "Results: " << sol.minDeletionSize(strs) << endl;

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/