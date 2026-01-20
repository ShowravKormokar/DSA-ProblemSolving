// Leetcode array 3314 -> Construct the Minimum Bitwise Array I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;

        for (const int num : nums)
            ans.push_back(num == 2 ? -1 : num - getLeadingOneOfLastGroupOfOnes(num));

        return ans;
    }

private:
    int getLeadingOneOfLastGroupOfOnes(int num)
    {
        int leadingOne = 1;
        while ((num & leadingOne) > 0)
            leadingOne <<= 1;
        return leadingOne >> 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result = sol.minBitwiseArray(nums);
    for (int val : result)
        cout << val << " ";
    return 0;
}

/*
TC: O(N), where N is the size of the input array nums. We iterate through
the array once, and each operation inside the loop takes constant time.
SC: O(N), where N is the size of the input array nums. We create a new array
ans to store the result, which takes O(N) space.
*/