// Leetcode problem 1722 -> Minimize Hamming Distance After Swap Operations
#include <bits/stdc++.h>
using namespace std;

// Understanding the problem partialy, need more time to understand the problem fully and then solve it using Union-Find data structure🚨❌☠️

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

    int find(int u)
    {
        return id[u] == u ? u : id[u] = find(id[u]);
    }

private:
    vector<int> id;
    vector<int> rank;
};

class Solution
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target,
                               vector<vector<int>> &allowedSwaps)
    {
        const int n = source.size();
        int ans = 0;
        UnionFind uf(n);
        vector<unordered_map<int, int>> groupIdToCount(n);

        for (const vector<int> &allowedSwap : allowedSwaps)
        {
            const int a = allowedSwap[0];
            const int b = allowedSwap[1];
            uf.unionByRank(a, b);
        }

        for (int i = 0; i < n; ++i)
            ++groupIdToCount[uf.find(i)][source[i]];

        for (int i = 0; i < n; ++i)
        {
            const int groupId = uf.find(i);
            unordered_map<int, int> &count = groupIdToCount[groupId];
            if (count.count(target[i]) == 0)
                ++ans;
            else if (--count[target[i]] == 0)
                count.erase(target[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
    cout << sol.minimumHammingDistance(source, target, allowedSwaps) << endl;
    return 0;
}

/*
TC: O(n + m) where n is the size of source and target and m is the size of allowedSwaps
SC: O(n) for the UnionFind data structure and the groupIdToCount vector
*/