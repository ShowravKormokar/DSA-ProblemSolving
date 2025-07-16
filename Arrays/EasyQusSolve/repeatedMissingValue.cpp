#include <bits/stdc++.h>
using namespace std;

vector<int> repMissValue(vector<vector<int>> &grid)
{
    int n = grid.size();
    int size = n * n;

    // Count frequency
    vector<int> freq(size + 1, 0);
    for (auto &row : grid)
    {
        for (auto val : row)
        {
            freq[val]++; // Count values that how many times present in the array
        }
    }

    int repeated = -1, missing = -1;
    for (int i = 0; i <= size; i++)
    {
        if (freq[i] == 2)
            repeated = i;
        else if (freq[i] == 0)
            missing = i;
    }

    return {repeated, missing};
}

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};

    vector<int> res = repMissValue(grid);
    for (auto val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}