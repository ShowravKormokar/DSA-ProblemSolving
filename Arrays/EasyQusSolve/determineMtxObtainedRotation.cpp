// Leetcode problem 1886 -> Determine Whether Matrix Can Be Obtained By Rotation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mat == target)
                return true;
            rotate(mat);
        }
        return false;
    }

private:
    void rotate(vector<vector<int>> &mat)
    {
        ranges::reverse(mat);
        for (int i = 0; i < mat.size(); ++i)
            for (int j = i + 1; j < mat.size(); ++j)
                swap(mat[i][j], mat[j][i]);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    cout << sol.findRotation(mat, target) << endl; // Output: true
    return 0;
}

/*
TC: O(n^2) for each rotation, and we do at most 4 rotations, so O(4 * n^2) = O(n^2)
SC: O(1) for in-place rotation, and O(1) for comparison, so overall O(1)
*/