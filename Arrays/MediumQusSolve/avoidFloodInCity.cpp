// Leetcode problem 1488 -> Avoid flood in the city
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = (int)rains.size();
        vector<int> ans(n, 1);            // default value 1 for dry days (will be overwritten)
        unordered_map<int, int> lastRain; // lake -> last day index it rained
        set<int> dryDays;                 // indices of days with rains[i] == 0

        for (int i = 0; i < n; ++i)
        {
            int lake = rains[i];
            if (lake > 0)
            {
                // It's a raining day for `lake`
                // If this lake has rained before and wasn't dried since, we must dry it
                if (lastRain.count(lake))
                {
                    int prev = lastRain[lake];
                    // find a dry day strictly after prev (so prev < dryDay < i)
                    auto it = dryDays.upper_bound(prev);
                    if (it == dryDays.end())
                    {
                        // no available dry day to prevent flood
                        return {};
                    }
                    // use this dry day to dry `lake`
                    ans[*it] = lake;   // assign that day to dry this lake
                    dryDays.erase(it); // remove that dry day from available set
                }
                // mark today as raining day; we cannot dry today -> set -1
                ans[i] = -1;
                lastRain[lake] = i; // update last rain day for this lake
            }
            else
            {
                // dry day -> keep as candidate (value 1 will be overwritten when used)
                dryDays.insert(i);
                // ans[i] remains 1 for now (valid if we never need to use it)
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> rains = {1, 0, 2, 0, 2, 1};
    for (auto r : sol.avoidFlood(rains))
    {
        cout << r << " "; // Outpput: -1 1 -1 2 -1 -1
    }
    cout << endl;
    return 0;
}

/*
TC: O(n*log*n)
SC: O(n)
*/