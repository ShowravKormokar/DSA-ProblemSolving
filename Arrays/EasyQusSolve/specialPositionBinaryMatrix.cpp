// Leetocode problem 1582 -> Special Positions in a Binary Matrix
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        const int m = mat.size();
        const int n = mat[0].size();
        int ans = 0;
        vector<int> rowOnes(m);
        vector<int> colOnes(n);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1)
                {
                    ++rowOnes[i];
                    ++colOnes[j];
                }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1)
                    ++ans;

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    cout << sol.numSpecial(mat) << endl; // Output: 1
    return 0;
}

/*
TC: O(m*n) where m is the number of rows and n is the number of columns in the matrix.
SC: O(m+n) for the rowOnes and colOnes vectors.
*/