// Leetcode problem 3512 -> Minimum Operations to Make Array Sum Divisible by K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int k = 6;
    cout << sol.minOperations(nums, k) << endl; // Output: 4
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/