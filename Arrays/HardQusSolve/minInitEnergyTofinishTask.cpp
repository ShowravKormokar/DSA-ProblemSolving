// Leetcode probelm 1665 -> Minimum Initial Energy to Finish Tasks
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        int ans = 0;
        int prevSaved = 0;

        ranges::sort(tasks, ranges::greater{},
                     [](const vector<int> &task)
                     { return task[1] - task[0]; });

        for (const vector<int> &task : tasks)
        {
            const int actual = task[0];
            const int minimum = task[1];
            if (prevSaved < minimum)
            {
                ans += minimum - prevSaved;
                prevSaved = minimum - actual;
            }
            else
            {
                prevSaved -= actual;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
    cout << sol.minimumEffort(tasks) << endl; // Output: 8
    return 0;
}

/*
TC: O(n log n) -> Sorting the tasks
SC: O(1) -> No extra space used, only a few variables to keep track of the current state
*/