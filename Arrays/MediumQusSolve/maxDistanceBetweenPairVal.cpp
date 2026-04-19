// Leetcode problem 1855 -> Maximum Distance Between a Pair of Values
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
            if (nums1[i] > nums2[j])
                ++i;
            else
                ans = max(ans, j++ - i);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4};

    cout << sol.maxDistance(nums1, nums2) << endl;

    return 0;
}

/*
TC: O(m + n) where m and n are the sizes of nums1 and nums2 respectively.
SC: O(1) as we are using only constant extra space.
*/