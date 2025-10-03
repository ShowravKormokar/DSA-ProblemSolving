// Leetcode problem 407 -> Trapping Rain Water II
#include <bits/stdc++.h>
using namespace std;

// Hard to understand : Need more knowledge about heap ❌🚨☠️

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0; // too small to hold water

        // Min-heap storing {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Push all boundary cells into heap
        for (int i = 0; i < m; i++)
        {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++)
        {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        vector<int> dirs = {0, 1, 0, -1, 0}; // for 4 directions

        // Step 2: Process heap
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int h = top[0], r = top[1], c = top[2];

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dirs[k], nc = c + dirs[k + 1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                    continue;

                visited[nr][nc] = true;

                // If neighbor small, so water trap
                if (heightMap[nr][nc] < h)
                {
                    water += h - heightMap[nr][nc];
                }

                // Effective height push in heap
                pq.push({max(h, heightMap[nr][nc]), nr, nc});
            }
        }

        return water;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};

    cout << "Trapped Water = " << sol.trapRainWater(heightMap) << endl;
    return 0;
}
