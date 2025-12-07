// Leetcode problem 1523 -> Count Odd Numbers in an Interval Range
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};

int main()
{
    Solution sol;
    int low = 3, high = 7;
    cout << "Count of odd numbers between " << low << " and " << high << " is: " << sol.countOdds(low, high) << endl;
    return 0;
}

/*
TC: O(1) - Constant time complexity since the solution involves only arithmetic operations.
SC: O(1) - Constant space complexity as no additional data structures are used.
*/