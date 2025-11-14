// Leetcode problem 2536 -> Increment Submatrices by One
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> prefix(n, vector<int>(n + 1));

        for (const vector<int> &query : queries)
        {
            const int row1 = query[0];
            const int col1 = query[1];
            const int row2 = query[2];
            const int col2 = query[3];
            for (int i = row1; i <= row2; ++i)
            {
                ++prefix[i][col1];
                --prefix[i][col2 + 1];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < n; ++j)
            {
                sum += prefix[i][j];
                ans[i][j] = sum;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    vector<vector<int>> result = sol.rangeAddQueries(n, queries);
    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << " "; // Output: 1 1 0 \n1 2 1 \n0 1 1
        }
        cout << endl;
    }
    return 0;
}

/*
TC: O(q + n^2) where q is the number of queries and n is the size of the matrix.
SC: O(n^2) for the prefix and answer matrices.
*/