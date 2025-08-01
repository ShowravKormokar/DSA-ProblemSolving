// Leetcode 118 problem -> Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(row);
    }

    return res;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);

    for (auto row : result)
    {
        for (auto r : row)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}