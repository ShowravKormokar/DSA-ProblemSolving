// Leetcode problem 3761 -> Minimum Absolute Distance Between Mirror Pairs
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n + 1;
        unordered_map<int, int> pos;
        auto reverse = [](int x)
        {
            int y = 0;
            for (; x > 0; x /= 10)
            {
                y = y * 10 + x % 10;
            }
            return y;
        };
        for (int i = 0; i < n; ++i)
        {
            if (pos.contains(nums[i]))
            {
                ans = min(ans, i - pos[nums[i]]);
            }
            pos[reverse(nums[i])] = i;
        }
        return ans > n ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 12, 11, 21};
    cout << sol.minMirrorPairDistance(nums) << endl; // Output: 2
    return 0;
}

/*
TC: O(n * log(max(nums[i]))) where n is the size of the input array and max(nums[i]) is the maximum value in the array. The log factor comes from reversing the digits of the numbers.
SC: O(n) for the unordered_map to store the positions of the numbers and their reversed counterparts.
*/