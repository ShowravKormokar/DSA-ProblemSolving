// Leetcode problem 3607. Power Grid Maintenance
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<int> parent(c + 1);
        for (int i = 0; i <= c; ++i)
        {
            parent[i] = i;
        }

        function<int(int)> find = [&](int i)
        {
            if (parent[i] == i)
            {
                return i;
            }
            parent[i] = find(parent[i]);
            return parent[i];
        };

        function<void(int, int)> union_sets = [&](int i, int j)
        {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j)
            {
                if (root_i < root_j)
                {
                    parent[root_j] = root_i;
                }
                else
                {
                    parent[root_i] = root_j;
                }
            }
        };

        for (const auto &connection : connections)
        {
            union_sets(connection[0], connection[1]);
        }

        unordered_map<int, vector<int>> component_members;
        for (int i = 1; i <= c; ++i)
        {
            int root = find(i);
            if (component_members.find(root) == component_members.end())
            {
                component_members[root] = {};
            }
            component_members[root].push_back(i);
        }

        unordered_set<int> offline;
        unordered_map<int, int> component_ptr;
        vector<int> results;

        for (const auto &query : queries)
        {
            int q_type = query[0];
            int x = query[1];

            if (q_type == 2)
            {
                offline.insert(x);
            }
            else
            {
                if (offline.find(x) == offline.end())
                {
                    results.push_back(x);
                }
                else
                {
                    int root = find(x);
                    int ptr = 0;
                    if (component_ptr.find(root) != component_ptr.end())
                    {
                        ptr = component_ptr[root];
                    }

                    vector<int> &members = component_members[root];

                    while (ptr < members.size() && offline.find(members[ptr]) != offline.end())
                    {
                        ptr++;
                    }

                    component_ptr[root] = ptr;

                    if (ptr < members.size())
                    {
                        results.push_back(members[ptr]);
                    }
                    else
                    {
                        results.push_back(-1);
                    }
                }
            }
        }

        return results;
    }
};

int main()
{
    Solution sol;
    int c = 5;
    vector<vector<int>> connections = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> queries = {{1, 2}, {2, 2}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    vector<int> result = sol.processQueries(c, connections, queries);
    for (int res : result)
    {
        cout << res << " ";
    }
    return 0;
}

/*
TC: O((C + N) * α(C)) where C is the number of cities, N is the number of queries, and α is the inverse Ackermann function.
SC: O(C + N)
*/