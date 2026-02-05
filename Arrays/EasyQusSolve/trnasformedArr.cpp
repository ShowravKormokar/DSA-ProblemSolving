// Leetcode problem 3379 -> Transformed Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int newIndex;
        int n = nums.size();

        vector<int> results(n);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                newIndex = (i + nums[i]) % n;
                results[i] = nums[newIndex];
            }
            else if (nums[i] < 0)
            {
                newIndex = ((i + nums[i]) % n + n) % n;
                results[i] = nums[newIndex];
            }
            else if (nums[i] == 0)
            {
                results[i] = nums[i];
            }
        }
        return results;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, -2, 1, 1};

    for (auto r : sol.constructTransformedArray(nums))
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}

/*
TC: O(n) -> we are iterating through the array once
SC: O(n) -> we are creating a new array to store the results
*/