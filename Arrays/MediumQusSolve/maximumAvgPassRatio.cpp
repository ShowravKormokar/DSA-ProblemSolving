// Leetcode problem 1792 -> Maximum Average Pass Ratio
#include <bits/stdc++.h>
using namespace std;

// Function to calculate gain
double gain(int p, int t)
{
    return (double)(p + 1) / (t + 1) - (double)p / t;
}

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    // Max heap sorting {gain,{p,t}}
    priority_queue<pair<double, pair<int, int>>> pq;

    for (auto &c : classes)
    {
        int p = c[0], t = c[1];
        pq.push({gain(p, t), {p, t}});
    }

    // Assign extra students greedily
    while (extraStudents--)
    {
        auto [g, pt] = pq.top();
        pq.pop();
        int p = pt.first, t = pt.second;
        p++, t++;
        pq.push({gain(p, t), {p, t}});
    }

    // Calculate final ratio
    double ans = 0.0;
    while (!pq.empty())
    {
        auto [g, pt] = pq.top();
        pq.pop();
        ans += (double)pt.first / pt.second;
    }

    return ans / classes.size();
}

int main()
{
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;

    cout << fixed << setprecision(6)
         << maxAverageRatio(classes, extraStudents) << endl; //Output: 0.783333
    return 0;
}

/*
- Used a max heap (priority queue) to always assign each extra student to the class with the maximum possible gain in pass ratio.
- Gain formula: gain = (p+1)/(t+1) - p/t where p = passed, t = total.
- For each extra student: pop the top class, add one passing student, then push it back with updated gain.
- Finally, compute the average of all class pass ratios.
- Time Complexity: O(extraStudents * log n + n), efficient for given constraints.
*/