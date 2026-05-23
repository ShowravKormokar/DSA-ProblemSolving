// Leetcode problem 1752 -> Check if Array Is Sorted and Rotated
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        const int n = nums.size();
        int rotates = 0;

        for (int i = 0; i < n; ++i)
            if (nums[i] > nums[(i + 1) % n] && ++rotates > 1)
                return false;

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << sol.check(nums) << endl; // Output: true
    return 0;
}

/*
TC: O(n) -> We traverse the array once to count the number of rotations.
SC: O(1) -> We use a constant amount of extra space to store the count of rotations and the size of the array.
*/