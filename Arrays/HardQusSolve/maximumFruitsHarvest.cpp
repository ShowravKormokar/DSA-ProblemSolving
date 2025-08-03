// Leetcode problem 2106 (Hard) -> Maximum fruits harvested after at most k steps
#include <bits/stdc++.h> // includes all standard C++ libraries
using namespace std;

// Function to check whether we can collect all fruits between index l and r within k steps
bool canReach(vector<vector<int>> &fruits, int l, int r, int startPos, int k)
{
    int leftMost = fruits[l][0];  // left-most fruit position in current window
    int rightMost = fruits[r][0]; // right-most fruit position in current window

    // Option-1: Go left first from startPos to leftMost, then go to rightMost
    long long cost1 = abs(startPos - leftMost) + abs(rightMost - leftMost);
    // Option-2: Go right first from startPos to rightMost, then go to leftMost
    long long cost2 = abs(startPos - rightMost) + abs(rightMost - leftMost);

    long long minCost = min(cost1, cost2); // minimum of two ways

    // Return true if we can cover the window within at most k steps
    return minCost <= k;
}

// Main function to compute maximum fruits collectable
int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
{
    int n = fruits.size(); // number of fruit patches

    // Prefix sums to calculate fruits in range [l, r] quickly
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + fruits[i][1]; // accumulate fruits count
    }

    long long ans = 0; // to store the maximum fruits collected
    int left = 0;      // left pointer of sliding window

    // r is the right pointer of sliding window
    for (int r = 0; r < n; r++)
    {
        // Shrink window from left while the segment [left, r] is not reachable within k steps
        while (left <= r && !canReach(fruits, left, r, startPos, k))
        {
            left++;
        }

        // If reachable, update answer with total fruits between left and r
        if (left <= r && canReach(fruits, left, r, startPos, k))
        {
            ans = max(ans, prefix[r + 1] - prefix[left]);
        }
    }

    return (int)ans; // maximum fruits
}

int main()
{
    // sample input
    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
    int startPos = 5, k = 4;

    cout << "Maximum fruits: " << maxTotalFruits(fruits, startPos, k) << endl;
    // prints answer

    return 0;
}