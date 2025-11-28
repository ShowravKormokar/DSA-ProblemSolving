// Leetcode problem 2872 -> Maximum Number of K-Divisible Components
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        int ans = 0;
        vector<vector<int>> graph(n);

        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(graph, 0, /*prev=*/-1, values, k, ans);
        return ans;
    }

private:
    long dfs(const vector<vector<int>> &graph, int u, int prev,
             const vector<int> &values, int k, int &ans)
    {
        long treeSum = values[u];

        for (const int v : graph[u])
            if (v != prev)
                treeSum += dfs(graph, v, u, values, k, ans);

        if (treeSum % k == 0)
            ++ans;
        return treeSum;
    }
};

int main()
{
    Solution sol;
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    vector<int> values = {2, 3, 5, 1, 1, 1, 1};
    int k = 3;

    int result = sol.maxKDivisibleComponents(n, edges, values, k);
    cout << "Maximum Number of K-Divisible Components: " << result << endl;

    return 0;
}

/*
TC: O(N) where N is the number of nodes in the tree.
SC: O(N) for the recursion stack and the graph representation.
*/