// Leetcode problem 3347 -> Maximum Frequency of an Element After Performing Operations II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int ans = 1;
        int adjustable = 0;
        unordered_map<int, int> count;
        map<int, int> line;
        set<int> candidates;

        for (const int num : nums)
        {
            ++count[num];
            ++line[num - k];
            --line[num + k + 1];
            candidates.insert(num);
            candidates.insert(num - k);
            candidates.insert(num + k + 1);
        }

        for (const int num : candidates)
        {
            // safely check key existence (since .contains() is C++20)
            if (line.find(num) != line.end())
                adjustable += line[num];

            int countNum = 0;
            if (count.find(num) != count.end())
                countNum = count[num];

            int adjusted = adjustable - countNum;
            ans = max(ans, countNum + min(numOperations, adjusted));
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 5};
    int k = 1, numOperations = 2;
    cout << "Result: " << sol.maxFrequency(nums, k, numOperations) << endl; // Output: 2
    return 0;
}

auto init = atexit([]()
                   { ofstream("display_runtime.txt") << '0'; });

/*
TC: O(n*logn)
SC: O(n)
*/