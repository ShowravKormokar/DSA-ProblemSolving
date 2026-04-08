// Leetcode problem 3653 -> XOR After Range Multiplication Queries I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int MOD = 1e9 + 7;

        for (auto &q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int idx = l; idx <= r; idx += k)
            {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums)
        {
            ans ^= x;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{0, 4, 2, 3}, {1, 3, 1, 2}};
    cout << sol.xorAfterQueries(nums, queries) << endl; // Output: 6
    return 0;
}

/*
TC: O(Q * (R - L) / K + N) where Q is the number of queries, R and L are the range limits, K is the step, and N is the size of the nums array.
SC: O(1) additional space, as we are modifying the nums array in place and using only a constant amount of extra space for variables.
*/