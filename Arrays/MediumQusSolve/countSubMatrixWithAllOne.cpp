// Leetcode problem 1504 -> Count submatrix with all ones
#include <bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> height(n, 0);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        // update histogram heights
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                height[j] = 0;
            else
                height[j] += 1;
        }

        // count submatrices ending at this row
        for (int j = 0; j < n; j++)
        {
            int minH = height[j];
            for (int k = j; k >= 0 && minH > 0; k--)
            {
                minH = min(minH, height[k]);
                ans += minH;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 1},
                               {1, 1, 0},
                               {1, 1, 0}};
    cout << "Results: " << numSubmat(mat) << endl; // Output: 13

    return 0;
}

/*
TC: O(m*n^2)
SC: O(n)
*/