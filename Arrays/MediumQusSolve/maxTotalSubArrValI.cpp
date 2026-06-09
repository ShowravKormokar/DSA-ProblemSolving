// Leetcode problem 3689 -> Maximum Total Subarray Value I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        return 1LL * k * (*mx - *mn);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << sol.maxTotalValue(nums, k) << endl; // Output: 12
    return 0;
}

/*
TC: O(n) - We traverse the array once to find the minimum and maximum elements.
SC: O(1) - We use a constant amount of extra space to store the minimum and maximum values.
*/