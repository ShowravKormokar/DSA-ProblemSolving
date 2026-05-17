// Leetcode problem 1306 -> Jump Game III
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        const int n = arr.size();
        queue<int> q{{start}};
        vector<bool> seen(n);

        while (!q.empty())
        {
            const int node = q.front();
            q.pop();
            if (arr[node] == 0)
                return true;
            if (seen[node])
                continue;
            // Check the available next steps.
            if (node - arr[node] >= 0)
                q.push(node - arr[node]);
            if (node + arr[node] < n)
                q.push(node + arr[node]);
            seen[node] = true;
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    cout << sol.canReach(arr, start) << endl;
    return 0;
}

/*
TC: O(n) -> We visit each node at most once.
SC: O(n) -> The queue and the seen array can grow up to size n in the worst case.
*/