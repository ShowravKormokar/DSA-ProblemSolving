//  Leetcode problem 1351 -> Count Negative Numbers in a Sorted Matrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        int i = m - 1;
        int j = 0;

        while (i >= 0 && j < n)
        {
            if (grid[i][j] < 0)
            {
                ans += n - j;
                --i;
            }
            else
            {
                ++j;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {};
    cout << "Result: " << sol.countNegatives(grid) << endl;

    return 0;
}

/*
TC: O(m+n)
SC: O(1)
*/