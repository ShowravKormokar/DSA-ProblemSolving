// Leetcode problem 3446 -> Sort Matrix by Diagonals

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
{
    const int n = grid.size();
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<int>> diag(2 * n + 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            diag[i - j + n].push_back(grid[i][j]);

    for (int i = 0; i < 2 * n + 1; ++i)
        if (i < n)
            sort(diag[i].begin(), diag[i].end(), greater<int>());
        else
            sort(diag[i].begin(), diag[i].end());

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i][j] = diag[i - j + n].back(), diag[i - j + n].pop_back();

    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> result = sortMatrix(grid);
    for (auto r : result)
    {
        for (auto v : r)
            cout << v << " "; // Output: [[8,2,3],[9,6,7],[4,5,1]]
        cout << endl;
    }
    return 0;
}

/*
TC: O(n^2)
SC: O(n^2)
*/