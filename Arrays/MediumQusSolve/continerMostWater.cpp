// Leetcode problem 11 -> Container with most water
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1, maxArea = 0;

    while (left < right)
    {
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;
        maxArea = max(maxArea, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Max area is: " << maxArea(height) << endl;

    return 0;
}