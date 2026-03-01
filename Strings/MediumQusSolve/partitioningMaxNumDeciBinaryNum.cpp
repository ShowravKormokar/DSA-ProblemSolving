// Leetcode problem 1689 -> Partitioning Into Minimum Number Of Deci-Binary Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        return *max_element(n.begin(), n.end()) - '0';
    }
};

int main()
{
    Solution sol;
    string n = "82734";
    cout << sol.minPartitions(n) << endl;
    return 0;
}

/*
TC: O(n) where n is the length of the input string n.
SC: O(1) as we are using only a constant amount of extra space.
*/