// Leetcode problem 3354 -> Make array element equal to zero
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();
        long long totalSum = 0;
        for (int v : nums)
            totalSum += v;

        int ans = 0;
        for (int start = 0; start < n; ++start)
        {
            if (nums[start] != 0)
                continue; // start must be zero

            // try both directions: -1 (left) and +1 (right)
            for (int initDir : {-1, 1})
            {
                vector<int> arr = nums; // work on a copy
                int curr = start;
                int d = initDir;

                // simulate until we go out of bounds
                // each time we hit positive value we decrement it => total decrements bounded by totalSum
                // so simulation always terminates
                while (curr >= 0 && curr < n)
                {
                    if (arr[curr] == 0)
                    {
                        curr += d;
                    }
                    else
                    {
                        arr[curr]--;
                        d = -d;
                        curr += d;
                    }
                }

                // check if all zero
                bool allZero = true;
                for (int v : arr)
                {
                    if (v != 0)
                    {
                        allZero = false;
                        break;
                    }
                }
                if (allZero)
                    ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 2, 0, 3};
    cout << "Result: " << sol.countValidSelections(nums) << endl; // Output: 2
    return 0;
}

/*
TC: O(n*(n+S))
SC: O(n)
*/