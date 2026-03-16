// Leetcode problem 1878 -> Get Biggest Three Rhombus Sums in a Grid
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        set<int> sums;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; ++sz)
                {
                    const int sum = sz == 0 ? grid[i][j] : getSum(grid, i, j, sz);
                    sums.insert(sum);
                    if (sums.size() > 3)
                        sums.erase(sums.begin());
                }

        return vector<int>(sums.rbegin(), sums.rend());
    }

private:
    // Returns the sum of the rhombus, where the top grid is (i, j) and the edge
    // size is `sz`.
    int getSum(const vector<vector<int>> &grid, int i, int j, int sz)
    {
        int x = i;
        int y = j;
        int sum = 0;

        // Go left down.
        for (int k = 0; k < sz; ++k)
            sum += grid[--x][++y];

        // Go right down.
        for (int k = 0; k < sz; ++k)
            sum += grid[++x][++y];

        // Go right up.
        for (int k = 0; k < sz; ++k)
            sum += grid[++x][--y];

        // Go left up.
        for (int k = 0; k < sz; ++k)
            sum += grid[--x][--y];

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<int> ans = sol.getBiggestThree(grid);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
TC: O(m * n * min(m, n)) where m and n are the number of rows and columns in the grid, respectively.
SC: O(1) if we don't consider the output list, otherwise O(3) = O(1) for the set that stores the sums of the rhombuses.
*/