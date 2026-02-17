// Leetcode problem 401 -> Binary Watch
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> ans;

        for (unsigned h = 0; h < 12; ++h)
            for (unsigned m = 0; m < 60; ++m)
                if (__builtin_popcount(h << 6 | m) == turnedOn)
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

        return ans;
    }
};

int main()
{
    Solution sol;
    int turnedOn = 1;
    vector<string> ans = sol.readBinaryWatch(turnedOn);
    for (string time : ans)
        cout << time << endl;
    return 0;
}

/*
TC: O(1) -> Since we are iterating through a fixed number of hours (12) and minutes (60), the time complexity is constant.
SC: O(1) -> The space complexity is also constant, as we are storing a fixed number of valid time combinations in the answer vector, which does not grow with input size.
*/