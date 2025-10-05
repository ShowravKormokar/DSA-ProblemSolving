// Leetcode problem 417 -> Pacific Atlatic Water Flow
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
            return {};

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<char>> pacific(m, vector<char>(n, 0));
        vector<vector<char>> atlantic(m, vector<char>(n, 0));

        vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};

        // iterative stack-based DFS to avoid recursion-depth issues
        auto bfs_from_border = [&](const vector<pair<int, int>> &starts, vector<vector<char>> &visited)
        {
            deque<pair<int, int>> dq;
            for (auto &s : starts)
            {
                dq.push_back(s);
                visited[s.first][s.second] = 1;
            }
            while (!dq.empty())
            {
                auto [r, c] = dq.front();
                dq.pop_front();
                for (int k = 0; k < 4; ++k)
                {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if (visited[nr][nc])
                        continue;
                    // we may move from the current cell to neighbor in reverse if neighbor.height >= current.height
                    if (heights[nr][nc] >= heights[r][c])
                    {
                        visited[nr][nc] = 1;
                        dq.emplace_back(nr, nc);
                    }
                }
            }
        };

        // Pacific starts: top row and left column
        vector<pair<int, int>> pacificStarts;
        for (int j = 0; j < n; ++j)
            pacificStarts.emplace_back(0, j);
        for (int i = 0; i < m; ++i)
            pacificStarts.emplace_back(i, 0);

        // Atlantic starts: bottom row and right column
        vector<pair<int, int>> atlanticStarts;
        for (int j = 0; j < n; ++j)
            atlanticStarts.emplace_back(m - 1, j);
        for (int i = 0; i < m; ++i)
            atlanticStarts.emplace_back(i, n - 1);

        bfs_from_border(pacificStarts, pacific);
        bfs_from_border(atlanticStarts, atlantic);

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        // Sort deterministically (row-major) for stable output
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    auto res = sol.pacificAtlantic(heights);
    cout << "Result:\n";
    for (auto &p : res)
    {
        cout << "[" << p[0] << "," << p[1] << "] "; // Output: [0,4] [1,3] [1,4] [2,2] [3,0] [3,1] [4,0]
    }
    cout << "\n";
    return 0;
}

/*
TC: O(m*n)
SC: O(m*n)
*/