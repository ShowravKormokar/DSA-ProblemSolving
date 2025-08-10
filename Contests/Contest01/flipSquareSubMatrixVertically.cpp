/*
You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.©leetcode

Example:
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3
Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]©leetcode
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
{
    int top = 0, bottom = k - 1;

    while (top < bottom)
    {
        for (int col = 0; col < k; col++)
        {
            swap(grid[x + top][y + col], grid[x + bottom][y + col]);
        }
        top++;
        bottom--;
    }
    return grid;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
    int x = 1, y = 0, k = 3;
    grid = reverseSubmatrix(grid, x, y, k);

    for (auto row : grid)
    {
        for (auto r : row)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}