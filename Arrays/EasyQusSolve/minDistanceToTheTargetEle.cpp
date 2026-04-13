// Leetcode problem 1848 -> Minimum Distance to the Target Element
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == target)
                ans = min(ans, abs(i - start));

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5, start = 3;

    cout << sol.getMinDistance(nums, target, start) << endl;

    return 0;
}

/*
TC: O(n) -> We traverse the array once to find the target element and calculate the minimum distance.
SC: O(1) -> We use a constant amount of extra space to store the minimum distance and the loop variable.
*/