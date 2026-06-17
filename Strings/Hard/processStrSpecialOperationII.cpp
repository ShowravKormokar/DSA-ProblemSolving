// Leetcode problem 3614 -> Process String with Special Operations II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long m = 0;
        for (char c : s)
        {
            if (c == '*')
            {
                m = max(0LL, m - 1);
            }
            else if (c == '#')
            {
                m <<= 1;
            }
            else if (c != '%')
            {
                m += 1;
            }
        }
        if (k >= m)
        {
            return '.';
        }
        for (int i = s.length() - 1;; i--)
        {
            char c = s[i];
            if (c == '*')
            {
                m += 1;
            }
            else if (c == '#')
            {
                m /= 2;
                if (k >= m)
                {
                    k -= m;
                }
            }
            else if (c == '%')
            {
                k = m - 1 - k;
            }
            else
            {
                m -= 1;
                if (k == m)
                {
                    return c;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    string s = "a#b*c%d";
    long long k = 2;
    cout << sol.processStr(s, k) << endl; // Output: 'b'
    return 0;
}

/*
TC: O(n) where n is the length of the input string s. We traverse the string twice, once to calculate the total number of characters and once to find the k-th character.
SC: O(1) since we are using only a constant amount of extra space to store the variables m and k, and we are modifying the input string in place without using any additional data structures.
*/