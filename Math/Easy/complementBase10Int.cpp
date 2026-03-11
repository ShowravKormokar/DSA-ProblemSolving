// Leetcode problem 1009 -> Complement of Base 10 Integer
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int mask = 1;
        while (mask < n)
            mask = (mask << 1) + 1;
        return mask ^ n;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << sol.bitwiseComplement(n) << endl; // Output: 2
    return 0;
}

/*
TC: O(log n) -> We are left shifting the mask until it becomes greater than n, which takes log n steps.
SC: O(1) -> We are using a constant amount of space for the mask variable.
*/