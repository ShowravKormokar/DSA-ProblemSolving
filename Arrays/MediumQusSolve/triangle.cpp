// Leetcode problem 120 -> Triangle
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // Started form second last row and move upward
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                // Update each cell with itself + minimum the two adjacent below
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        // Top element contains the minimum path sum
        return triangle[0][0];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << "Minimum path sum: " << sol.minimumTotal(triangle) << endl; // Output: 11
    return 0;
}

/*
TC: O(n^2)
SC: O(1)
*/