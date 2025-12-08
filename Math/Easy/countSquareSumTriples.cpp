// Leetcode problem 1925 -> Count Square Sum Triples
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        int ans = 0;
        unordered_set<int> squared;

        for (int i = 1; i <= n; ++i)
            squared.insert(i * i);

        for (const int a : squared)
            for (const int b : squared)
                if (squared.find(a + b) != squared.end())
                    ++ans;

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << sol.countTriples(n) << endl; // Output: 2
    return 0;
}

/*
TC: O(n^2) where n is the input number. We have two nested loops each running n times.
SC: O(n) for storing the squared values in the unordered_set.
*/