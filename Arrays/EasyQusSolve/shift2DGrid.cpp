// Leetcode problem 1260 -> Shift 2D Grid
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        k %= m * n;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                const int index = (i * n + j + k) % (m * n);
                const int x = index / n;
                const int y = index % n;
                ans[x][y] = grid[i][j];
            }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;

    vector<vector<int>> result = sol.shiftGrid(grid, k);

    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
TC: O(m * n) where m is the number of rows and n is the number of columns in the grid.
SC: O(m * n) for the answer grid.
*/