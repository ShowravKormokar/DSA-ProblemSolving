// Leetcode problem 2078 -> Two Furthest Houses With Different Colors
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        // The maximum distance always includes either the first or the last house.
        const int n = colors.size();
        int i = 0;     // the leftmost index, where colors[i] != colors[-1]
        int j = n - 1; // the rightmost index, where colors[j] != colors[0]
        while (colors[i] == colors.back())
            ++i;
        while (colors[j] == colors.front())
            --j;
        return max(n - 1 - i, j);
    }
};

int main()
{
    Solution sol;
    vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
    cout << sol.maxDistance(colors) << endl; // Output: 3
    return 0;
}

/*
TC: O(n) -> We may need to traverse the entire array in the worst case.
SC: O(1) -> We are using only a constant amount of extra space.
*/