// Leetcode problem 1975 -> Maximum Matrix Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long absSum = 0;
        int minAbs = INT_MAX;
        // 0 := even number of negatives
        // 1 := odd number of negatives
        int oddNeg = 0;

        for (const vector<int> &row : matrix)
            for (const int num : row)
            {
                absSum += abs(num);
                minAbs = min(minAbs, abs(num));
                if (num < 0)
                    oddNeg ^= 1;
            }

        return absSum - oddNeg * minAbs * 2;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{-1, -2, -3}, {-4, 5, 6}, {7, 8, 9}};
    cout << sol.maxMatrixSum(matrix) << endl; // Output: 45
    return 0;
}

/*
TC: O(n * m) where n and m are the number of rows and columns in the matrix respectively.
SC: O(1)
*/