// Leetcode problem 1727. Largest Submatrix With Rearrangements
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        const int n = matrix[0].size();
        int ans = 0;
        vector<int> hist(n);

        for (const vector<int> &row : matrix)
        {
            // Accumulate the histogram if possible.
            for (int i = 0; i < n; ++i)
                hist[i] = row[i] == 0 ? 0 : hist[i] + 1;

            // Get the sorted histogram.
            vector<int> sortedHist(hist);
            ranges::sort(sortedHist);

            // Greedily calculate the answer.
            for (int i = 0; i < n; ++i)
                ans = max(ans, sortedHist[i] * (n - i));
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    cout << sol.largestSubmatrix(matrix) << endl; // Output: 4
    return 0;
}

/*
TC: O(m * n log n), where m is the number of rows and n is the number of columns in the matrix. We iterate through each row and sort the histogram for each row, which takes O(n log n) time.
SC: O(n), where n is the number of columns in the matrix. We use a histogram array of size n to store the heights of the columns, and a sorted histogram array of the same size to calculate the maximum area.
*/