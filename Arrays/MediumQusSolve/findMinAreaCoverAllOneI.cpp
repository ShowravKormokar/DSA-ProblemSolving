// Leetcode problem 3195 -> Find the Minimum Area to Cover All Ones I
#include <bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int minRow = m, maxRow = -1;
    int minCol = n, maxCol = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;
    return height * width;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 0}, {1, 0, 1}};
    cout << "Minimum Area: " << minimumArea(grid) << endl;
    return 0;
}

/*
TC: O(m*n)
SC: O(1)
*/