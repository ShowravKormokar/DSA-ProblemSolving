// Leetcode problem 3634 -> Minimum Removals to Balance Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0;
        int maxLen = 1; // at least 1 element is valid

        for (int right = 0; right < n; right++)
        {
            while ((long long)nums[right] > (long long)nums[left] * k)
            {
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << sol.minRemoval(nums, k) << endl; // Output: 2
    return 0;
}

/*
TC: O(n log n) due to sorting, where n is the size of the input array.
SC: O(1) if we ignore the space used for sorting, otherwise O(n)
*/