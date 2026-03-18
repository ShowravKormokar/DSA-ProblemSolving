// Leetcode problem 3070 -> Count Submatrices with Top-Left Element and Sum Less Than k
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                prefix[i + 1][j + 1] =
                    grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
                if (prefix[i + 1][j + 1] <= k)
                    ++ans;
            }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 10;
    cout << sol.countSubmatrices(grid, k) << endl; // Output: 4
    return 0;
}

/*
TC: O(m*n) where m and n are the number of rows and columns in the grid respectively.
SC: O(m*n) for the prefix sum matrix.
*/