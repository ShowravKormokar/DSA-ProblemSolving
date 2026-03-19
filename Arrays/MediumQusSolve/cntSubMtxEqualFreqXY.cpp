// Leetcode problem 3212 -> Count Submatrices With Equal Frequency of X and Y
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> countX(n, vector<int>(m, 0));
        vector<vector<int>> countY(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // current cell contribution
                int x = (grid[i][j] == 'X');
                int y = (grid[i][j] == 'Y');

                // build prefix sum
                countX[i][j] = x;
                countY[i][j] = y;

                if (i > 0)
                {
                    countX[i][j] += countX[i - 1][j];
                    countY[i][j] += countY[i - 1][j];
                }
                if (j > 0)
                {
                    countX[i][j] += countX[i][j - 1];
                    countY[i][j] += countY[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    countX[i][j] -= countX[i - 1][j - 1];
                    countY[i][j] -= countY[i - 1][j - 1];
                }

                // check condition
                if (countX[i][j] == countY[i][j] && countX[i][j] > 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'X', 'Y', 'X'},
        {'Y', 'X', 'Y'},
        {'X', 'Y', 'X'}};

    cout << sol.numberOfSubmatrices(grid) << endl; // Output: 5

    return 0;
}

/*
TC: O(n*m) where n and m are the dimensions of the grid.
SC: O(n*m) for the prefix sum arrays countX and countY.
*/