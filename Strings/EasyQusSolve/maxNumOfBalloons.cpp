// Leetcode problem 1189 -> Maximum Number of Balloons
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int ans = INT_MAX;
        vector<int> count(26);

        for (char c : text)
            ++count[c - 'a'];

        for (char c : string("ban"))
            ans = min(ans, count[c - 'a']);

        for (char c : string("lo"))
            ans = min(ans, count[c - 'a'] / 2);

        return ans;
    }
};

int main()
{
    Solution sol;
    string text = "loonbalxballpoon";
    cout << sol.maxNumberOfBalloons(text) << endl; // Output: 2
    return 0;
}

/*
TC: O(n) where n is the length of the input string text.
SC: O(1) since the size of the count vector is constant (26).
*/