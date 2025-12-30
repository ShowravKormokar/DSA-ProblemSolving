// Leecode problem 840 -> Magic Squares In Grid
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < m; i++)
        {
            for (int j = 0; j + 2 < n; j++)
            {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }

private:
    bool isMagic(vector<vector<int>> &g, int r, int c)
    {
        // Center must be 5
        if (g[r + 1][c + 1] != 5)
            return false;

        vector<bool> seen(10, false);

        // Check numbers 1–9 uniqueness
        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v])
                    return false;
                seen[v] = true;
            }
        }

        // Check rows & columns
        for (int i = 0; i < 3; i++)
        {
            if (g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2] != 15)
                return false;
            if (g[r][c + i] + g[r + 1][c + i] + g[r + 2][c + i] != 15)
                return false;
        }

        // Check diagonals
        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != 15)
            return false;
        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != 15)
            return false;

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};

    cout << "Result: " << sol.numMagicSquaresInside(grid) << endl;

    return 0;
}

// 8 1 6
// 3 5 7
// 4 9 2

/*
TC: O(m*n)
SC: O(1)
*/