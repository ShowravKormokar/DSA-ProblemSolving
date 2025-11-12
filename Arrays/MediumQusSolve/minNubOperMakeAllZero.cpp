// Leetcode problem 2654 -> Minimum Number of Operations to Make All Array Elements Equal to 1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0)
            return n - ones;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int g = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                g = gcd(g, nums[j]);
                if (g == 1)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return (ans - 1) + (n - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4};
    cout << "Minimum operations: " << sol.minOperations(nums) << endl;
    return 0;
}

/*
TC: O(N^2 * logM) where N is the size of the array and M is the maximum element in the array.
SC: O(1)
*/