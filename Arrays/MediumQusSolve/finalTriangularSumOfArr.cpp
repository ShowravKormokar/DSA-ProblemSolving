// Leetcode problem 2221 -> Find Triangular Sum of an Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> C(n, 0);
        C[0] = 1;

        // Determine Binomial coefficient by using Pascal's triangle
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j > 0; j--)
            {
                C[j] = (C[j] + C[j - 1]) % 10;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + C[i] * nums[i]) % 10;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Triangular Sum = " << sol.triangularSum(nums) << endl; // Output: 8
    return 0;
}
/*
TC: O(n)
SC: O(1)
*/