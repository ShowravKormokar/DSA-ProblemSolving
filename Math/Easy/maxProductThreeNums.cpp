// Leetcode problem 628 -> Maximum Product of Three Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        const int n = nums.size();
        ranges::sort(nums);
        return max(nums[n - 1] * nums[0] * nums[1],
                   nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.maximumProduct(nums) << endl; // Output: 6
    return 0;
}

/*
TC: O(nlogn) -> Sorting the array
SC: O(1) -> No extra space used
*/