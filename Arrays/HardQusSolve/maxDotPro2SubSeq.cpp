// Leetcode problem 1458 -> Max Dot Product of Two Subsequences
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j] = max dot product using nums1[0..i] and nums2[0..j]
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int prod = nums1[i] * nums2[j];

                // option 1: start new subsequence from this pair
                dp[i][j] = prod;

                // option 2: extend previous subsequence
                if (i > 0 && j > 0)
                    dp[i][j] = max(dp[i][j], prod + max(0, dp[i - 1][j - 1]));

                // option 3: skip from nums1
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);

                // option 4: skip from nums2
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    cout << sol.maxDotProduct(nums1, nums2) << endl; //Output: 18
    return 0;
}

/*
TC: O(n*m)
SC: O(n*m)
*/