// Leetcode problem 3507 -> Minimum Pair Removal to Sort Array I
#include <bits/stdc++.h>
using namespace std;

#include <ranges>

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int ans = 0;

        while (hasInversion(nums))
        {
            vector<int> pairSums;
            for (const auto &[a, b] : views::pairwise(nums))
                pairSums.push_back(a + b);
            const int minPairSum = ranges::min(pairSums);
            const int minPairIndex =
                ranges::find(pairSums, minPairSum) - pairSums.begin();
            nums[minPairIndex] = minPairSum;
            nums.erase(nums.begin() + minPairIndex + 1);
            ++ans;
        }

        return ans;
    }

private:
    bool hasInversion(const vector<int> &nums)
    {
        for (const auto &[a, b] : views::pairwise(nums))
            if (a > b)
                return true;
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 3, 2, 4, 1};
    cout << sol.minimumPairRemoval(nums) << endl; // Output the result
    return 0;
}

/*
TC: O(n^2)
SC: O(1)
*/