// Leetcode problem 1018 -> Binary Prefix Divisible By 5
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans;
        int curr = 0;
        for (auto num : nums)
        {
            curr = (curr * 2 + num) % 5;
            ans.push_back(curr % 5 == 0);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 1, 1, 1, 1};
    vector<bool> result = sol.prefixesDivBy5(nums);
    for (bool res : result)
    {
        cout << (res ? "true" : "false") << " "; // Output the results
    }
    return 0;
}

/*
TC: O(N)
SC: O(1)
*/