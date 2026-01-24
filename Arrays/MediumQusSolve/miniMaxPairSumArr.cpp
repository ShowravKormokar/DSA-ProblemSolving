// Leetcode problem 1877 -> Minimize Maximum Pair Sum in Array
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int ans = 0;

        ranges::sort(nums);

        for (int i = 0, j = nums.size() - 1; i < j;)
            ans = max(ans, nums[i++] + nums[j--]);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 5, 2, 3};
    cout << sol.minPairSum(nums) << endl; // Output: 7
    return 0;
}

/*
TC: O(N log N) due to sorting the array.
SC: O(1) as we are using only constant extra space.
*/