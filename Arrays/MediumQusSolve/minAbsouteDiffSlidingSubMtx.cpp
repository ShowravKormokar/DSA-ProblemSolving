// Leetcode problem 3567 -> Minimum Absolute Difference in Sliding Submatrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize result matrix with dimensions (rows - k + 1) x (cols - k + 1)
        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1, 0));

        // Iterate through all possible k x k subgrids
        for (int startRow = 0; startRow <= rows - k; ++startRow)
        {
            for (int startCol = 0; startCol <= cols - k; ++startCol)
            {

                // Collect all elements from the current k x k subgrid
                vector<int> subgridElements;
                for (int row = startRow; row < startRow + k; ++row)
                {
                    for (int col = startCol; col < startCol + k; ++col)
                    {
                        subgridElements.push_back(grid[row][col]);
                    }
                }

                // Sort elements to find minimum absolute difference between adjacent distinct values
                sort(subgridElements.begin(), subgridElements.end());

                // Find minimum absolute difference between consecutive distinct elements
                int minDifference = INT_MAX;
                for (int i = 1; i < subgridElements.size(); ++i)
                {
                    // Only consider distinct consecutive elements
                    if (subgridElements[i] != subgridElements[i - 1])
                    {
                        int currentDifference = abs(subgridElements[i] - subgridElements[i - 1]);
                        minDifference = min(minDifference, currentDifference);
                    }
                }

                // If no distinct elements found (all elements are same), set difference to 0
                result[startRow][startCol] = (minDifference == INT_MAX) ? 0 : minDifference;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 3, 5}, {2, 4, 6}, {7, 8, 9}};
    int k = 2;
    vector<vector<int>> result = sol.minAbsDiff(grid, k);

    // Print the result
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
TC: O((m-k+1)*(n-k+1)*k^2*log(k^2)) where m and n are the dimensions of the grid, and k is the size of the submatrix. This is because we iterate through each possible starting point for the k x k submatrix, collect its elements, sort them, and then find the minimum absolute difference.
SC: O(k^2) for storing the elements of the current k x k submatrix during processing. The result matrix takes O((m-k+1)*(n-k+1)) space, but this is required for the output and does not affect the auxiliary space complexity.
*/