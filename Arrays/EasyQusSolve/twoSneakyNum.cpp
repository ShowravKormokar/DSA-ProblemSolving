// Leetcode problem 3289 -> The Two Sneaky Numbers of Digitville
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<int> ans;

        for (auto f : freq)
        {
            if (f.second == 2)
            {
                ans.push_back(f.first);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    for (auto num : sol.getSneakyNumbers(nums))
    {
        cout << num << " "; // Output: 4 5
    }
    cout << endl;
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/