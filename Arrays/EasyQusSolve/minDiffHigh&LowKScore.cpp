// Leetcode problem 1984 -> Minimum Difference Between Highest and Lowest of K Scores
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        // ranges::sort(nums);
        sort(nums.begin(), nums.end());

        int ans = nums[k - 1] - nums[0];

        for (int i = k; i < nums.size(); ++i)
            ans = min(ans, nums[i] - nums[i - k + 1]);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {90};
    int k = 1;
    cout << sol.minimumDifference(nums, k) << endl; // Output: 0
    return 0;
}

/*
TC: O(N log N) due to sorting the array.
SC: O(1) as we are using only a constant amount of extra space.
*/