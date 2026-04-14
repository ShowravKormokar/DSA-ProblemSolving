// Leetcode problem 2463 -> Minimum Total Distance Traveled
#include <bits/stdc++.h>
using namespace std;

// Unsolved: Need to solve using dynamic programming and spend more time to properly understand the problem statement and constraints.☠️❌🚨😥

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot,
                                   vector<vector<int>> &factory)
    {
        ranges::sort(robot);
        ranges::sort(factory);
        vector<vector<vector<long>>> mem(
            robot.size(),
            vector<vector<long>>(factory.size(), vector<long>(robot.size())));
        return minimumTotalDistance(robot, factory, 0, 0, 0, mem);
    }

private:
    // Returns the minimum distance to fix robot[i..n) with factory[j..n), where
    // factory[j] already fixed k robots.
    long minimumTotalDistance(const vector<int> &robot,
                              const vector<vector<int>> &factory, int i, int j,
                              int k, vector<vector<vector<long>>> &mem)
    {
        if (i == robot.size())
            return 0;
        if (j == factory.size())
            return LONG_MAX;
        if (mem[i][j][k] > 0)
            return mem[i][j][k];
        const long skipFactory =
            minimumTotalDistance(robot, factory, i, j + 1, 0, mem);
        const int position = factory[j][0];
        const int limit = factory[j][1];
        const long useFactory =
            limit > k ? minimumTotalDistance(robot, factory, i + 1, j, k + 1, mem) +
                            abs(robot[i] - position)
                      : LONG_MAX / 2;
        return mem[i][j][k] = min(skipFactory, useFactory);
    }
};

int main()
{
    Solution sol;
    vector<int> robot = {0, 4, 6};
    vector<vector<int>> factory = {{2, 2}, {6, 2}};
    cout << sol.minimumTotalDistance(robot, factory) << endl;
    return 0;
}

/*
TC: O(n * m * k) where n is the number of robots, m is the number of factories, and k is the maximum number of robots a factory can fix.
SC: O(n * m * k) for the memoization table.
*/