// Leetcode problem 3296 -> Minimum Number of Seconds to Make Mountain Height Zero
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        long l = 1;
        long r = static_cast<long>(ranges::min(workerTimes)) * mountainHeight *
                 (mountainHeight + 1) / 2;

        while (l < r)
        {
            const long m = (l + r) / 2;
            if (getReducedHeight(workerTimes, m) < mountainHeight)
                l = m + 1;
            else
                r = m;
        }

        return l;
    }

private:
    // Returns the total height reduced by all workers in `m` seconds.
    int getReducedHeight(const vector<int> &workerTimes, long m)
    {
        int reducedHeight = 0;
        for (const int workerTime : workerTimes)
            // The height `x` that a worker with working time `w` reduces in `m`
            // seconds.
            // w * (1 + 2 + ... + x) <= m
            //       (1 + x) * x / 2 <= m / w
            //   x^2 + x - 2 * m / w <= 0
            //                     x <= (-1 + sqrt(1 + 8 * m / w)) / 2
            reducedHeight += (-1 + sqrt(1 + 8 * m / workerTime)) / 2;
        return reducedHeight;
    }
};

int main()
{
    Solution sol;
    int mountainHeight = 4;
    vector<int> workerTimes = {1, 2, 3};
    cout << sol.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}

/*
TC: O(n log(m)), where n is the number of workers and m is the maximum time calculated for the binary search.
SC: O(1), as we are using only a constant amount of extra space.
*/