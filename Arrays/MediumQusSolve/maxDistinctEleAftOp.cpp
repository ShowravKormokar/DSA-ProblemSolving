// Leetcode problem 3397 -> Maximum Number of Distinct Elements After Operations
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        // occupied = last assigned distinct value
        long long occupied = LLONG_MIN; // use 64-bit to avoid overflow

        for (long long num : nums)
        {
            // if the highest possible we can push (num+k) is > occupied,
            // that means there's room to assign a new distinct value
            if (occupied < num + k)
            {
                // assign new distinct value = max(occupied + 1, num - k)
                long long candidate = max(occupied + 1, num - k);
                occupied = candidate;
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 4};
    int k = 2;
    cout << "Result: " << sol.maxDistinctElements(nums, k) << endl; // Output: 6
    return 0;
}

/*
TC: O(n*log*n)
SC: O(1)
*/