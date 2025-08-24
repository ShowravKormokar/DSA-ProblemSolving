// Leetcode problem 1493 -> Longest Subarray of 1's After Deleting One Element
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int ans = 0;
    int zeros = 0;

    for (int l = 0, r = 0; r < nums.size(); r++)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }
        while (zeros == 2)
        {
            if (nums[l++] == 0)
            {
                zeros--;
            }
        }
        ans = max(ans, r - l);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1};
    cout << "The longest subarray: " << longestSubarray(nums) << endl; // Output: 3
    return 0;
}

/*
TC: O(N)
SC: O(1)
*/