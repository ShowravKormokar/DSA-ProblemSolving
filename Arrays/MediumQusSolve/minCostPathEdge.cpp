// Leetcode problem 3650 -> Minimum Cost Path with Edge Reversals
#include <bits/stdc++.h>
using namespace std;

// Hard to undestand ❌☠️🚨
class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<int, vector<pair<int, int>>> rev_adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            rev_adj[v].push_back({u, w});
        }

        vector<long long> dist(2 * n, numeric_limits<long long>::max());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            long long d = pq.top().first;
            int u_exp = pq.top().second;
            pq.pop();

            if (d > dist[u_exp])
            {
                continue;
            }

            int u = u_exp % n;
            int state = u_exp / n;

            // Traverse normal outgoing edges
            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                int v_exp = v;
                if (d + w < dist[v_exp])
                {
                    dist[v_exp] = d + w;
                    pq.push({dist[v_exp], v_exp});
                }
            }

            if (state == 0)
            {
                // Use the switch at u (0-cost state transition)
                int u_switched_exp = u + n;
                if (d < dist[u_switched_exp])
                {
                    dist[u_switched_exp] = d;
                    pq.push({dist[u_switched_exp], u_switched_exp});
                }
            }
            else
            { // state == 1
                // Traverse a reversed incoming edge
                for (auto &edge : rev_adj[u])
                {
                    int v = edge.first;
                    int w = edge.second;
                    int v_exp = v;
                    if (d + 2 * w < dist[v_exp])
                    {
                        dist[v_exp] = d + 2 * w;
                        pq.push({dist[v_exp], v_exp});
                    }
                }
            }
        }

        long long min_cost = min(dist[n - 1], dist[n - 1 + n]);

        return (min_cost == numeric_limits<long long>::max()) ? -1 : (int)min_cost;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {1, 0, 1},
        {2, 1, 1},
        {3, 2, 1},
        {4, 3, 1}};
    cout << sol.minCost(n, edges) << endl; // Output the minimum cost
    return 0;
}
