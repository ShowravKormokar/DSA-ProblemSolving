// Leetcode probelem 2553 -> Separate the Digits in an Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;

        for (const int num : nums)
            for (const char c : to_string(num))
                ans.push_back(c - '0');

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {13, 25, 83, 77};
    vector<int> ans = sol.separateDigits(nums);

    for (const int num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}

/*
TC:O(N) where N is the total number of digits in all the numbers in the input array.
SC:O(N) where N is the total number of digits in all the numbers in the input array, as we are storing the separated digits in a new array.
*/