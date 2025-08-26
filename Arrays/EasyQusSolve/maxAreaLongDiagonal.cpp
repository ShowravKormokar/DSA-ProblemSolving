// Leetcode problem 3000 -> Maximum Area of Longest Diagonal Rectangle
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
{
    const vector<int> maxDimension = *max_element(
        dimensions.begin(), dimensions.end(),
        [](const vector<int> &a, const vector<int> &b)
        {
            int da = a[0] * a[0] + a[1] * a[1];
            int db = b[0] * b[0] + b[1] * b[1];
            if (da == db)
                return a[0] * a[1] < b[0] * b[1];
            return da < db;
        });
    return maxDimension[0] * maxDimension[1];
}

int main()
{
    vector<vector<int>> dimensions = {{9, 3}, {8, 6}};
    cout << areaOfMaxDiagonal(dimensions) << endl; // Output: 48
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/