// Leetcode problem 1464 -> Maximum Product of Two Elements in an Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max1 = 0;
        int max2 = 0;

        for (const int num : nums)
            if (num > max1)
                max2 = std::exchange(max1, num);
            else if (num > max2)
                max2 = num;

        return (max1 - 1) * (max2 - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 2};
    cout << sol.maxProduct(nums) << endl; // Output: 12
    return 0;
}

/*
TC: O(n) - We traverse the array once to find the two largest numbers.
SC: O(1) - We use a constant amount of space for the two largest numbers
*/