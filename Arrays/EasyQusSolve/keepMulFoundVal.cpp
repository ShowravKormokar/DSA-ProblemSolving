// Leetcode problem 2154 -> Keep Multiplying Found Values by Two
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        int i = 0;
        int store = original;
        while (i < nums.size())
        {
            if (store == nums[i])
            {
                store = store * 2;
                i = 0;
            }
            else
            {
                i++;
            }
        }

        return store;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;
    cout << sol.findFinalValue(nums, original);
    return 0;
}

/*
TC: O(N^2) in worst case, where N is the size of the input array nums.
SC: O(1) as we are using only a constant amount of extra space.
*/