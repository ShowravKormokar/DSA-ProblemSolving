// Leetcode problem 1674 -> Minimum Moves to Make Array Complementary
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {
        const int n = nums.size();
        int ans = n;
        // delta[i] := the number of moves needed when target goes from i - 1 to i
        vector<int> delta(limit * 2 + 2);

        for (int i = 0; i < n / 2; ++i)
        {
            const int a = nums[i];
            const int b = nums[n - 1 - i];
            --delta[min(a, b) + 1];
            --delta[a + b];
            ++delta[a + b + 1];
            ++delta[max(a, b) + limit + 1];
        }

        // Initially, we need `moves` when the target is 2.
        for (int i = 2, moves = n; i <= limit * 2; ++i)
        {
            moves += delta[i];
            ans = min(ans, moves);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 4, 3};
    int limit = 4;
    cout << sol.minMoves(nums, limit) << endl; // Output: 1
    return 0;
}

/*
TC: O(n + k) where n is the size of the input array and k is the limit.
SC: O(k) where k is the limit.
*/