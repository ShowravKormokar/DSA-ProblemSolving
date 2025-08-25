// Leetcode problem 498 -> Diagonal Traverse
#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    if (mat.empty() || mat[0].empty())
        return {};

    int m = mat.size(), n = mat[0].size();
    vector<int> result;
    result.reserve(m * n);

    int row = 0, col = 0, dir = 1; // Dir =1: Up right and Dir=-1: down left

    while (result.size() < m * n)
    {
        result.push_back(mat[row][col]);

        if (dir == 1) // moving up-right
        {
            if (col == n - 1) // reached right boundary
            {
                row++;
                dir = -1;
            }
            else if (row == 0) // reached top boundary
            {
                col++;
                dir = -1;
            }
            else // normal move
            {
                row--;
                col++;
            }
        }
        else // moving down-left
        {
            if (row == m - 1) // reached bottom boundary
            {
                col++;
                dir = 1;
            }
            else if (col == 0) // reached left boundary
            {
                row++;
                dir = 1;
            }
            else // normal move
            {
                row++;
                col--;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> result = findDiagonalOrder(mat);
    for (auto r : result)
    {
        cout << r << " "; // Output: 1 2 4 7 5 3 6 8 9
    }
    cout << "\n";

    return 0;
}

/*
TC: O(m*n)
SC: O(1)
*/