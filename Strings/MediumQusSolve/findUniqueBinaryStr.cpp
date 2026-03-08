// Leetcode problem 1980 -> Find Unique Binary String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        const int bitSize = nums[0].length();
        const int maxNum = 1 << bitSize;
        unordered_set<int> numsSet;

        for (const string &num : nums)
            numsSet.insert(stoi(num, nullptr, 2));

        for (int num = 0; num < maxNum; ++num)
            if (numsSet.find(num) == numsSet.end())
                return std::bitset<16>(num).to_string().substr(16 - bitSize);

        throw;
    }
};

int main()
{
    Solution sol;
    vector<string> nums = {"01", "10"};
    cout << sol.findDifferentBinaryString(nums) << endl; // Output: "11"
    return 0;
}

/*
TC: O(n) where n is the number of binary strings in the input vector. We iterate through the input vector once to populate the unordered_set, and then we iterate through all possible binary numbers up to 2^bitSize to find a unique one.
SC: O(n) for the unordered_set that stores the integer representations of the binary strings.
*/