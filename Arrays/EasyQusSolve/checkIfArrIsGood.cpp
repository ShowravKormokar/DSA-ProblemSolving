// Leetcode problem 2784 -> Check if Array is Good
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        constexpr int kMax = 200;
        const int n = nums.size() - 1;
        vector<int> count(kMax + 1);

        for (const int num : nums)
            ++count[num];

        return all_of(count.begin() + 1, count.begin() + n, [](int c)
                      { return c == 1; }) &&
               count[n] == 2;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << boolalpha << sol.isGood(nums) << endl; // Output: true
    return 0;
}

/*
TC: O(n) where n is the size of the input array `nums`. We iterate through the array once to count the occurrences of each number, which takes O(n) time. The subsequent check to verify the counts takes O(n) time in the worst case, but since we are only checking up to `n`, it can be considered O(1) in terms of the size of the input.
SC: O(n) in the worst case, where n is the size of the input array `nums`. We use an additional vector `count` of size 201 to store the count of each number, which takes O(1) space. However, if we consider the input size, the space complexity can be considered O(n) due to the input array itself.
*/