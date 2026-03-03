// Leetcode problem 1545 -> Find Kth Bit in Nth Binary String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';
        const int midIndex = pow(2, n - 1); // 1-indexed
        if (k == midIndex)
            return '1';
        if (k < midIndex)
            return findKthBit(n - 1, k);
        return findKthBit(n - 1, midIndex * 2 - k) == '0' ? '1' : '0';
    }
};

int main()
{
    Solution sol;
    int n = 4, k = 11;
    cout << sol.findKthBit(n, k) << endl; // Output: "1"
    return 0;
}

/*
TC: O(n) -> In the worst case, we may need to go down to the base case n = 1, which takes O(n) time.
SC: O(n) -> The maximum depth of the recursion is n, which means we can have at most n function calls on the call stack at any given time. Therefore, the space complexity is O(n) due to the recursive call stack.
*/