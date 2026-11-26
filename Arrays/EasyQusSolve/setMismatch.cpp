// Leetcode problem Set Mismatch
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(2, 0);
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == 2)
            {
                ans[0] = i;
            }
            else if (freq[i] == 0)
            {
                ans[1] = i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = s.findErrorNums(nums);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}

// TC: O(n)
// SC: O(n)