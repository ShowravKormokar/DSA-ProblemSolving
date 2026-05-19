// Leetcode problem 2540 -> Minimum Common Value
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0; // nums1's index
        int j = 0; // nums2's index

        while (i < nums1.size() && j < nums2.size())
        {   
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] < nums2[j])
                ++i;
            else
                ++j;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {2, 3, 4, 5};
    cout << sol.getCommon(nums1, nums2) << endl; // Output: 2
    return 0;
}

/*
TC: O(n + m) where n and m are the sizes of nums1 and nums2 respectively.
SC: O(1) since we are using only a constant amount of extra space.
*/