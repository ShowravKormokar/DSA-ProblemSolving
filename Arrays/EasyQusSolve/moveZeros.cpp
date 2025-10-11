// Leetcode problem 283 -> Move zeros
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                res[j++] = nums[i];
        }
        while (j < n)
            res[j++] = 0;

        for (int i = 0; i < n; i++)
            nums[i] = res[i];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);

    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}