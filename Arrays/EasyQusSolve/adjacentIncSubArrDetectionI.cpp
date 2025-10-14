// Leetcode problem 3349 -> Adjacent Increasing Subarrays Detection I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int increasing = 1;
        int prevIncreasing = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++increasing;
            }
            else
            {
                prevIncreasing = increasing;
                increasing = 1;
            }
            if (increasing / 2 >= k || min(prevIncreasing, increasing) >= k)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int k = 3;
    cout << "Is true: " << sol.hasIncreasingSubarrays(nums, k) << endl;
    return 0;
}