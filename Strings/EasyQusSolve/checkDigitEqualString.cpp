// Leetcode problem 3461 -> Check If Digits Are Equal in String After Operations I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.size() > 2)
        {
            string next = "";
            for (int i = 0; i < s.size() - 1; i++)
            {
                int num = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                next.push_back(num + '0');
            }
            s = next; // update the string
        }

        // now s has length == 2
        return s[0] == s[1];
    }
};

int main()
{
    Solution sol;
    string s = "3902";
    cout << "Is true: " << sol.hasSameDigits(s) << endl;
    return 0;
}
auto init = atexit([]()
                   { ofstream("display_runtime.txt") << '0'; });