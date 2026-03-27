// Leetcode problem 2946. Matrix Similarity After Cyclic Shifts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        const int n = mat[0].size();
        for (const vector<int> &row : mat)
            for (int j = 0; j < n; ++j)
                if (row[j] != row[(j + k) % n])
                    return false;
        return true;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int k = 2; // cyclic shift amount

    bool result = sol.areSimilar(mat, k);

    if (result)
        cout << "The matrix is similar after " << k << " cyclic shifts." << endl;
    else
        cout << "The matrix is NOT similar after " << k << " cyclic shifts." << endl;

    return 0;
}

/*
TC: O(mn)
SC: O(1)
*/