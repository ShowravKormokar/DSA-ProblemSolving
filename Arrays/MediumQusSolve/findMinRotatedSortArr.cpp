// Leetcode problem: 153 -> Find Minimum in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            const int m = (l + r) / 2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }

        return nums[l];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums) << endl; // Output: 1
    return 0;
}

/*
TC: O(log n) - Binary search is used to find the minimum element in the rotated sorted array.
SC: O(1) - We are using only a constant amount of extra space to store the pointers and variables.
*/