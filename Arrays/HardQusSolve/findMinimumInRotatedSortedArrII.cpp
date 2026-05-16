// Leetcode problem 154 -> Find Minimum in Rotated Sorted Array II
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
            if (nums[m] == nums[r])
                --r;
            else if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }

        return nums[l];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << s.findMin(nums) << endl;
    return 0;
}

/*
TC: O(log n) in the average case, O(n) in the worst case when all elements are the same.
SC: O(1) as we are using only constant extra space.
*/