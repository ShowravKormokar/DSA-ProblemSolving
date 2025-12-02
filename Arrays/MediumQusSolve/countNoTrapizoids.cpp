// Leetcode problem 3623 -> Count Number of Trapezoids I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        const int mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (auto &p : points)
        {
            cnt[p[1]]++;
        }
        long long ans = 0, s = 0;
        for (auto &[_, v] : cnt)
        {
            long long t = 1LL * v * (v - 1) / 2;
            ans = (ans + s * t) % mod;
            s += t;
        }
        return (int)ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 0},
                                  {2, 0},
                                  {3, 0},
                                  {2, 2},
                                  {3, 2}};
    cout << "Result: " << sol.countTrapezoids(points) << endl;
    return 0;
}

// Time Complexity: O(N), where N is the number of points
// Space Complexity: O(N) for the unordered_map