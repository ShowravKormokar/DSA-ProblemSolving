// Leetcode problem 14 -> Longest common prefix
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0];

    for (int i = 0; i < strs.size(); i++)
    {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix == "")
            return "";
    }
    return prefix;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);
    return 0;
}