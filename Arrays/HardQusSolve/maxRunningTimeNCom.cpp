// Leetcode problem 3513 -> Maximum Running Time of N Computers
#include <bits/stdc++.h>
using namespace std;

// This problem may not properly understand 🚨☠️

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long sum = accumulate(batteries.begin(), batteries.end(), 0L);

        std::sort(batteries.begin(), batteries.end());

        // The maximum battery is greater than the average, so it can last forever.
        // Reduce the problem from size n to size n - 1.
        while (batteries.back() > sum / n)
        {
            sum -= batteries.back(), batteries.pop_back();
            --n;
        }

        // If the maximum battery <= average running time, it won't be waste, and so
        // do smaller batteries.
        return sum / n;
    }
};

int main()
{
    Solution sol;
    vector<int> batteries = {3, 3, 3};
    int n = 2;

    cout << "Result: " << sol.maxRunTime(n, batteries) << endl;
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/