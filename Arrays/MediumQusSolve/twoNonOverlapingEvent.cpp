// Leetcode problem 2054 -> Two Best Non-Overlapping Events
#include <bits/stdc++.h>
using namespace std;

struct Event
{
    int time;
    int value;
    bool isStart;
};

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int ans = 0;
        int maxValue = 0;
        vector<Event> evts;

        for (const vector<int> &event : events)
        {
            const int start = event[0];
            const int end = event[1];
            const int value = event[2];
            evts.emplace_back(start, value, true);
            evts.emplace_back(end + 1, value, false);
        }

        ranges::sort(evts, ranges::less{}, [](const Event &evt)
                     { return pair<int, bool>{evt.time, evt.isStart}; });

        for (const auto &[_, value, isStart] : evts)
            if (isStart)
                ans = max(ans, value + maxValue);
            else
                maxValue = max(maxValue, value);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << "Results: " << sol.maxTwoEvents(events) << endl;
    return 0;
}

/*
TC: O(sort)
SC: O(n)
*/