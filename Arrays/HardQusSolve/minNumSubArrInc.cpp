// Leetcode problem 1526 -> Minimum Number of Increments on Subarrays to Form a Target Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int ans = target.front();
        for (int i = 1; i < target.size(); i++)
        {
            if (target[i] > target[i - 1])
            {
                ans += target[i] - target[i - 1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> target = {1, 2, 3, 2, 1};
    cout << "Result: " << sol.minNumberOperations(target) << endl; // Output: 3
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/