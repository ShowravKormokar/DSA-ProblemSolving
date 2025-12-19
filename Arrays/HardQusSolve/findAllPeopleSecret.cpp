// Leetcode problem 2092 -> Find All People With Secret
#include <bits/stdc++.h>
using namespace std;

// Hard to understand, need more practice with Union-Find ☠️🚨

class UnionFind
{
public:
    UnionFind(int n) : id(n), rank(n)
    {
        iota(id.begin(), id.end(), 0);
    }

    void unionByRank(int u, int v)
    {
        const int i = find(u);
        const int j = find(v);
        if (i == j)
            return;
        if (rank[i] < rank[j])
        {
            id[i] = j;
        }
        else if (rank[i] > rank[j])
        {
            id[j] = i;
        }
        else
        {
            id[i] = j;
            ++rank[j];
        }
    }

    bool connected(int u, int v)
    {
        return find(u) == find(v);
    }

    void reset(int u)
    {
        id[u] = u;
    }

private:
    vector<int> id;
    vector<int> rank;

    int find(int u)
    {
        return id[u] == u ? u : id[u] = find(id[u]);
    }
};

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                              int firstPerson)
    {
        vector<int> ans;
        UnionFind uf(n);
        map<int, vector<pair<int, int>>> timeToPairs;

        uf.unionByRank(0, firstPerson);

        for (const vector<int> &meeting : meetings)
        {
            const int x = meeting[0];
            const int y = meeting[1];
            const int time = meeting[2];
            timeToPairs[time].push_back({x, y});
        }

        for (const auto &[_, pairs] : timeToPairs)
        {
            unordered_set<int> peopleUnioned;
            for (const auto &[x, y] : pairs)
            {
                uf.unionByRank(x, y);
                peopleUnioned.insert(x);
                peopleUnioned.insert(y);
            }
            for (const int person : peopleUnioned)
                if (!uf.connected(person, 0))
                    uf.reset(person);
        }

        for (int i = 0; i < n; ++i)
            if (uf.connected(i, 0))
                ans.push_back(i);

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 6;
    vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int firstPerson = 1;

    vector<int> result = sol.findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int person : result)
    {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}

/*
TC: O(M log M + M α(N)) where M is the number of meetings and N is the number of people.
SC: O(N + M) for the Union-Find data structure and the map to store meetings by time.
*/
