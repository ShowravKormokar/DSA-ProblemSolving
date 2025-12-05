// Leetcode problem -> 3432. Count Partitions with Even Sum Difference
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0) % 2 == 0 ? nums.size() - 1 : 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 10, 3, 7, 6};
    cout << "Result: " << sol.countPartitions(nums) << endl;
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/