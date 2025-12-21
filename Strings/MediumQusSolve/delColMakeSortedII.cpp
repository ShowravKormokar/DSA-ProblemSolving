// Leetcode problem 955 -> Delete Columns to Make Sorted II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        const int n = strs.size();
        int ans = 0;

        vector<bool> sorted(n - 1);

        for (int j = 0; j < strs[0].length(); ++j)
        {
            int i;
            for (i = 0; i + 1 < n; ++i)
                if (!sorted[i] && strs[i][j] > strs[i + 1][j])
                {
                    ++ans;
                    break;
                }

            if (i + 1 == n)
                for (i = 0; i + 1 < n; ++i)
                    sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"ca", "bb", "ac"};
    cout << "Result: " << sol.minDeletionSize(strs) << endl;
    return 0;
}

/*
TC: O(∣strs[0]∣⋅n)
SC: O(n)
*/