// Leetcode problem 3514 -> Number of Unique XOR Triplets II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int mx = ranges::max(nums) << 1;

        vector<bool> st(mx, false);
        for (int a : nums)
        {
            for (int b : nums)
            {
                st[a ^ b] = true;
            }
        }

        vector<int> s(mx, 0);
        for (int ab = 0; ab < mx; ab++)
        {
            if (st[ab])
            {
                for (int c : nums)
                {
                    s[ab ^ c] = 1;
                }
            }
        }

        return accumulate(s.begin(), s.end(), 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = sol.uniqueXorTriplets(nums);
    cout << "Number of unique XOR triplets: " << result << endl;

    return 0;
}

/*
TC: O(n^2) since we are iterating through all pairs of elements in the input array to compute their XOR values, and then iterating through the unique pairs to compute the triplet XOR values.
SC: O(n^2) since we are storing all unique pairs of XOR values in a set, which can potentially have up to n^2 unique values in the worst case.
*/