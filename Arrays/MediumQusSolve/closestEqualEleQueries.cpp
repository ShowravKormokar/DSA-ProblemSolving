// Leetcode problem 3488 -> Closest Equal Element Queries
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        const int n = nums.size();
        vector<int> ans;
        // minDist[i] := the minimum distance between nums[i], and any other index j
        // in the circular array, where nums[j] == nums[i]
        vector<int> minDist(n, n);
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < n * 2; ++i)
        {
            const int index = i % n;
            const int num = nums[index];
            if (const auto it = lastSeen.find(num); it != lastSeen.cend())
            {
                const int prevIndex = it->second % n;
                const int d = i - prevIndex;
                minDist[index] = min(minDist[index], d);
                minDist[prevIndex] = min(minDist[prevIndex], d);
            }
            lastSeen[num] = i;
        }

        for (const int query : queries)
            ans.push_back(minDist[query] == n ? -1 : minDist[query]);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    vector<int> queries = {0, 1, 2, 3};
    vector<int> ans = sol.solveQueries(nums, queries);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

/*
TC: O(n + q) where n is the size of nums and q is the size of queries
SC: O(n) for the minDist vector and the lastSeen map
*/