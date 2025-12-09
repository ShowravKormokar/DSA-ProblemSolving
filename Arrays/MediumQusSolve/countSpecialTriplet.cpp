// Leetcode problem 3583 -> Count Special Triplets
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        unordered_map<int, int> leftCount;
        unordered_map<int, int> rightCount;

        // Initialize rightCount with all elements
        for (int num : nums)
        {
            rightCount[num]++;
        }

        long long result = 0;
        const int MOD = 1e9 + 7;

        for (int middleValue : nums)
        {
            rightCount[middleValue]--;

            int targetValue = middleValue * 2;
            result = (result + 1LL * leftCount[targetValue] * rightCount[targetValue] % MOD) % MOD;

            leftCount[middleValue]++;
        }

        return static_cast<int>(result);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 3, 6};
    cout << "Result: " << sol.specialTriplets(nums) << endl; // Output: 1
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/