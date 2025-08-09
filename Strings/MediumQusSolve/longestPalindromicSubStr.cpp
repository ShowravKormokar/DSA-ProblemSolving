// Leetcode problem 5 -> Longest palindromic substring
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    int start = 0, maxLen = 0;

    auto expand = [&](int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen)
            {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < s.size(); i++)
    {
        expand(i, i);
        expand(i, i + 1);
    }

    return s.substr(start, maxLen);
}

int main()
{
    string s = "babad";

    cout << "Longest Palindrome: " << longestPalindrome(s) << endl;

    return 0;
}