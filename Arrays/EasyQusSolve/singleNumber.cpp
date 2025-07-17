// Leetcode 136 -> Single number

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    // Way 01
    unordered_map<int, int> freq;
    for (auto num : nums)
    {
        freq[num]++;// No. of same element exist
    }

    for (auto &p : freq)
    {
        if (p.second == 1)
            return p.first;
    }

    /* Way 02
    int result =0;
    for (auto num: nums)
    {
        result ^= num; // work when only one unique element exist
    }
    return result;
    */

    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};

    cout << "Single value: " << singleNumber(nums) << endl;

    return 0;
}