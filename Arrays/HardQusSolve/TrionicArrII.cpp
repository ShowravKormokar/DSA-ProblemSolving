// Leetcode problem 3638 -> Trionic Array II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<tuple<int, int, long long>> decompose(vector<int> &nums)
    {
        int n = (int)nums.size();
        vector<tuple<int, int, long long>> subarrays;

        int l = 0;
        long long sum = nums[0];

        for (int i = 1; i < n; i++)
        {
            // If we fail strict decreasing at boundary i-1 -> i, end the current subarray.
            if (nums[i - 1] <= nums[i])
            {
                subarrays.push_back({l, i - 1, sum});
                l = i;
                sum = 0;
            }
            sum += nums[i];
        }
        // last subarray
        subarrays.push_back({l, n - 1, sum});
        return subarrays;
    }
    long long maxSumTrionic(vector<int> &nums)
    {
        int n = (int)nums.size();
        long long maxEndingAt[n];
        for (int i = 0; i < n; i++)
        {
            maxEndingAt[i] = nums[i];
            if (i > 0 && nums[i - 1] < nums[i])
            {
                if (maxEndingAt[i - 1] > 0)
                {
                    maxEndingAt[i] += maxEndingAt[i - 1];
                }
            }
        }
        long long maxStartingAt[n];
        for (int i = n - 1; i >= 0; i--)
        {
            maxStartingAt[i] = nums[i];
            if (i < n - 1 && nums[i] < nums[i + 1])
            {
                if (maxStartingAt[i + 1] > 0)
                {
                    maxStartingAt[i] += maxStartingAt[i + 1];
                }
            }
        }
        vector<tuple<int, int, long long>> PQS = decompose(nums);
        long long ans = LLONG_MIN;
        for (auto [p, q, sum] : PQS)
        {

            if (p > 0 && nums[p - 1] < nums[p] &&
                q < n - 1 && nums[q] < nums[q + 1] &&
                p < q)
            {
                ans = max(ans, maxEndingAt[p - 1] + sum + maxStartingAt[q + 1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, -2, -1, -3, 0, 2, -1};
    cout << "Result: " << sol.maxSumTrionic(nums) << endl;
    return 0;
}

/*
TC: O(N) where N is the size of the input array nums. We traverse the array a few times (for maxEndingAt, maxStartingAt, and decompose), but each traversal is O(N).
SC: O(N) due to the maxEndingAt and maxStartingAt arrays, as well as the subarrays vector that can hold up to O(N) subarrays in the worst case.
*/