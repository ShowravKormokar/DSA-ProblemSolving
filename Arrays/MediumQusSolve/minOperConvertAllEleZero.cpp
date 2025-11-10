// Leetcode problem 3542 -> Minimum Operations to Convert All Elements to Zero
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        stack<int> stack;
        stack.push(0);

        for (const int num : nums)
        {
            while (!stack.empty() && stack.top() > num)
                stack.pop();
            if (stack.empty() || stack.top() < num)
            {
                ++ans;
                stack.push(num);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 0, 3, 5};
    cout << "Minimum operations to convert all elements to zero: " << sol.minOperations(nums) << endl;
    return 0;
}

/*
TC: O(N) where N is the number of elements in the input array nums.
SC: O(N) in the worst case, where all elements are pushed onto the stack.
*/