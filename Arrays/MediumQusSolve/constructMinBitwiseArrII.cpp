// Leetcode problem 3315 -> COnstruct the Minimum Bitwise Array II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Same as 3314. Construct the Minimum Bitwise Array I
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;

        for (const int num : nums)
            ans.push_back(num == 2 ? -1 : num - getLeadingOneOfLastGroupOfOnes(num));

        return ans;
    }

private:
    // Returns the leading one of the last group of 1s in the binary
    // representation of num. For example, if num = 0b10111, the leading one of
    // the last group of 1s is 0b100.
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

    cout << "Result: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}

/*
TC: O(N), where N is the size of the input array nums. We iterate through
the array once to construct the result.
SC: O(N), the space used to store the result array.
*/