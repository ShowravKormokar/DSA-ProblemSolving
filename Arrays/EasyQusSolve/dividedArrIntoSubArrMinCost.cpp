// Leetcode problem 3010 -> Divide an Array Into Subarrays With Minimum Cost I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        constexpr int kMax = 50;
        int min1 = kMax;
        int min2 = kMax;

        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2)
            {
                min2 = nums[i];
            }

        return nums[0] + min1 + min2;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 4, 5};
    cout << "Minimum Cost: " << sol.minimumCost(nums) << endl;
    return 0;
}

/*
TC: O(N) where N is the size of the input array nums.
SC: O(1) as we are using only a constant amount of extra space.
*/