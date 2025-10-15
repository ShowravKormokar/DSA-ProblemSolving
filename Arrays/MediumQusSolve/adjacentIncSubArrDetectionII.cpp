// Leetcode problem 3350 -> Adjacent Increasing Subarrays Detection II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        int ans = 0;
        int curr = 1; // current increasing run length (counts current element)
        int prev = 0; // previous run length

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++curr;
            }
            else
            {
                prev = curr;
                curr = 1;
            }
            ans = max(ans, curr / 2);        // same run gives floor(curr/2)
            ans = max(ans, min(prev, curr)); // adjacent runs give min(prev,curr)
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    cout << "Result: " << sol.maxIncreasingSubarrays(nums) << endl; // Output: 3
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/