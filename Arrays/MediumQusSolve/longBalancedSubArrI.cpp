// Leetcode problem 3719 -> Longest Balanced Subarray I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> even, odd;

            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                if (even.size() == odd.size())
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << sol.longestBalanced(nums) << endl; // Output: 6
    return 0;
}

/*
TC: O(n^2) -> Two nested loops
SC: O(n) -> In the worst case, we may store all elements in the set
*/