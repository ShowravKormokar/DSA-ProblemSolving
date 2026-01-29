// Leetcode problem 2976 -> Minimum Cost to Convert String I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        long minCost = 0;
        vector<vector<long>> dist(26, vector<long>(26, LONG_MAX));

        for (int i = 0; i < cost.size(); ++i)
        {
            const int u = original[i] - 'a';
            const int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], static_cast<long>(cost[i]));
        }

        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (dist[i][k] < LONG_MAX)
                {
                    for (int j = 0; j < 26; ++j)
                    {
                        if (dist[k][j] < LONG_MAX)
                        {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < source.length(); ++i)
        {
            if (source[i] == target[i])
                continue;
            const int u = source[i] - 'a';
            const int v = target[i] - 'a';
            if (dist[u][v] == LONG_MAX)
                return -1;
            minCost += dist[u][v];
        }

        return minCost;
    }
};

int main()
{
    Solution sol;
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};

    cout << "Result: " << sol.minimumCost(source, target, original, changed, cost) << endl;

    return 0;
}

/*
TC: O(N^3 + M) where N is the number of characters in the alphabet (26 for lowercase English letters) and M is the length of the source/target strings.
SC: O(N^2) for the distance matrix.
*/