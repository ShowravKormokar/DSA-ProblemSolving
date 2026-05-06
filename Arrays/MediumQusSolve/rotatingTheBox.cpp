// Leetcode problem 1861 -> Rotating the Box
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        const int m = box.size();
        const int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i)
            for (int j = n - 1, k = n - 1; j >= 0; --j)
                if (box[i][j] != '.')
                {
                    if (box[i][j] == '*')
                        k = j;
                    ans[k--][m - i - 1] = box[i][j];
                }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> box = {{'#', '.', '#'}};
    vector<vector<char>> ans = sol.rotateTheBox(box);
    for (const auto &row : ans)
    {
        for (const auto &ch : row)
            cout << ch << " ";
        cout << endl;
    }
    return 0;
}

/*
TC: O(m*n) -> We traverse the entire box once.
SC: O(m*n) -> We create a new 2D vector 'ans' of size n x m to store the rotated box.
*/