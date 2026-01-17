// Leetcode problem 3047 -> Find the Largest Area of Square Inside Two Rectangles
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int left = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right = min(topRight[i][0], topRight[j][0]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top = min(topRight[i][1], topRight[j][1]);

                if (right > left && top > bottom)
                {
                    long long side = min(right - left, top - bottom);
                    maxArea = max(maxArea, side * side);
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {6, 6}};

    cout << "Result: " << sol.largestSquareArea(bottomLeft, topRight) << endl; // Output: 1

    return 0;
}

/*
TC: O(n^2)
SC: O(1)
*/