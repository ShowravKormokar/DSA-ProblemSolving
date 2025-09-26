// Leetcode problem 611 -> Valid triangle number
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += (j - i);
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 2, 3, 4};
    cout << "Valid triangle count: " << sol.triangleNumber(nums) << endl; // Output: 3

    vector<int> nums2 = {4, 2, 3, 4};
    cout << "Valid triangle count: " << sol.triangleNumber(nums2) << endl; // Output: 4

    return 0;
}

/*
TC: O(n^3)
SC: O(1)
*/