// Leetcode problem 48 -> Rotate Image
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        ranges::reverse(matrix);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i + 1; j < matrix.size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
TC: O(n^2) - We traverse the matrix twice, once for reversing and once for transposing.
SC: O(1) - We perform the operations in-place without using any additional data structures.
*/