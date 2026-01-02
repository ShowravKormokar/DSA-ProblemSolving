// Leetcode problem 961 -> N-Repeated Element in Size 2N Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto num : nums)
        {
            freq[num]++;
        }
        int result = 0;
        int maxFreq = 0;
        for (auto &pair : freq)
        {
            if (pair.second > maxFreq)
            {
                maxFreq = pair.second;
                result = pair.first;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "Results: " << sol.repeatedNTimes(nums) << endl; // Output: 2
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/