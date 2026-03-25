// Leetcode problem 3546 -> Equal Sum Grid Partition I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        const long totalSum = accumulate(grid.begin(), grid.end(), 0L,
                                         [](long acc, const vector<int> &row)
                                         {
                                             return acc + accumulate(row.begin(), row.end(), 0L);
                                         });
        return canPartition(grid, totalSum) ||
               canPartition(transposed(grid), totalSum);
    }

private:
    bool canPartition(const vector<vector<int>> &lines, long totalSum)
    {
        long runningSum = 0;
        for (const vector<int> &line : lines)
        {
            runningSum += accumulate(line.begin(), line.end(), 0L);
            if (runningSum * 2 == totalSum)
                return true;
        }
        return false;
    }

    vector<vector<int>> transposed(const vector<vector<int>> &grid)
    {
        vector<vector<int>> res(grid[0].size(), vector<int>(grid.size()));
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                res[j][i] = grid[i][j];
        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {1, 2, 3},
        {3, 2, 1}};

    if (sol.canPartitionGrid(grid))
        cout << "Possible to partition\n";
    else
        cout << "Not possible to partition\n";

    return 0;
}

/*
TC: O(n * m)
SC: O(n * m)
*/