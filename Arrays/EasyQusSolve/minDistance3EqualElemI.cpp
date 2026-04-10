// Leetcode problem 3740 -> Minimum Distance Between Three Equal Elements I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i)
        {
            g[nums[i]].push_back(i);
        }
        const int inf = 1 << 30;
        int ans = inf;
        for (auto &[_, ls] : g)
        {
            int m = ls.size();
            for (int h = 0; h < m - 2; ++h)
            {
                int i = ls[h];
                int k = ls[h + 2];
                int t = (k - i) * 2;
                ans = min(ans, t);
            }
        }
        return ans == inf ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1};
    cout << sol.minimumDistance(nums) << endl; // Output: 4
    return 0;
}

/*
TC: O(n) - We traverse the input array once to build the map, and then we iterate through the map to find the minimum distance. The overall time complexity is O(n).
SC: O(n) - We use an unordered map to store the indices of each unique element in the input array. In the worst case, if all elements are unique, the space complexity will be O(n).
*/