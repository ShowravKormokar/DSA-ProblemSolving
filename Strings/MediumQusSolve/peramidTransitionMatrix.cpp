// Leetcode problem 756 -> Pyramid Transition Matrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<string, vector<char>> prefixToBlocks;

        for (const string &a : allowed)
            prefixToBlocks[a.substr(0, 2)].push_back(a[2]);

        return dfs(bottom, "", 0, prefixToBlocks);
    }

private:
    bool dfs(const string &row, const string &nextRow, int i,
             const unordered_map<string, vector<char>> &prefixToBlocks)
    {
        if (row.length() == 1)
            return true;
        if (nextRow.length() + 1 == row.length())
            return dfs(nextRow, "", 0, prefixToBlocks);

        const string &prefix = row.substr(i, 2);

        if (const auto it = prefixToBlocks.find(prefix);
            it != prefixToBlocks.cend())
            for (const char c : it->second)
                if (dfs(row, nextRow + c, i + 1, prefixToBlocks))
                    return true;

        return false;
    }
};

int main()
{
    Solution sol;
    string bottom = "BCD";
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};

    cout << "Result: " << sol.pyramidTransition(bottom, allowed) << endl;

    return 0;
}