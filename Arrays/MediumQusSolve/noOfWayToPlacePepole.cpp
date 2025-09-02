// Leetcode problem 3025 -> Find the Number of Ways to Place People I
#include <bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<vector<int>> &points)
{
    int n = points.size();
    sort(points.begin(), points.end(),
         [](auto &a, auto &b)
         {
             if (a[0] != b[0])
                 return a[0] < b[0];
             return a[1] > b[1];
         });
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int yi = points[i][1];
        int maxY = INT_MIN;
        for (int j = i + 1; j < n; ++j)
        {
            int yj = points[j][1];
            if (yj <= yi && yj > maxY)
            {
                ans++;
                maxY = yj;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{6, 2}, {4, 4}, {2, 6}};
    cout << "Result: " << numberOfPairs(points) << endl; // Output: 2
    return 0;
}

/*
TC: O(n^2*k)
SC: O(n)

1. Store all points in a hash/set for O(1) lookup.
2. Iterate over all pairs (A, B).
   - Ensure A.x < B.x and A.y > B.y (upper-left condition).
   - Check if any point exists inside/on the rectangle.
3. If no point found, count the pair as valid.
This ensures correctness with optimized checks using hashing.
*/