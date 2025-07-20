// Leetcode 74 problem -> Search a 2D Matrix
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Use binary search method
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, heigh = m * n - 1;
    while (low <= heigh)
    {
        int mid = low + (heigh - low) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            heigh = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 3);

    return 0;
}