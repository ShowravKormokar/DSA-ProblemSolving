// Leetcode problem 1716 -> Calculate money in leetcode bank
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7; // Full weeks
        int days = n % 7;  // Remaining days
        int total = 0;

        // Calculate money for full weeks
        total += weeks * 28 + (weeks * (weeks - 1) / 2) * 7;

        // Calculate money for remaining days
        total += days * (weeks + 1) + (days * (days - 1)) / 2;

        return total;
    }
};

int main()
{
    Solution sol;
    int n = 26;
    cout << "Reult: " << sol.totalMoney(n) << endl; // Output: 135
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/