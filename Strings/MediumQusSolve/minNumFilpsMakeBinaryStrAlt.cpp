// Leetcode problem 1888 -> Minimum Number of Flips to Make the Binary String Alternating
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        const int n = s.length();
        vector<vector<int>> count(2, vector<int>(2));

        for (int i = 0; i < n; ++i)
            ++count[s[i] - '0'][i % 2];

        int ans = min(count[1][0] + count[0][1], count[0][0] + count[1][1]);

        for (int i = 0; i < n; ++i)
        {
            --count[s[i] - '0'][i % 2];
            ++count[s[i] - '0'][(n + i) % 2];
            ans = min({ans, count[1][0] + count[0][1], count[0][0] + count[1][1]});
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "111000";
    cout << sol.minFlips(s) << endl;
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/