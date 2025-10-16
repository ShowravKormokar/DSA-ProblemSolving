// Leetcode problem 2598 -> Smallest Missing Non-negative Integer After Operations
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_map<int, int> freq;
        for (auto num : nums)
        {
            int r = ((num % value) + value) % value;
            freq[r]++;
        }
        int x = 0;
        while (true)
        {
            int r = x % value;
            if (freq[r] > 0)
                freq[r]--;
            else
                return x;
            x++;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 5;
    cout << "Result: " << sol.findSmallestInteger(nums, value) << endl; // Output: 4
    return 0;
}

/*
TC: O(m+n)
SC: O(value)
*/