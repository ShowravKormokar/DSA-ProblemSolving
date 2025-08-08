// Leetcode problem 3 (string,Medium) -> Longest substring without repeating characters
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> lastIndex;
    int maxLen = 0, start = 0;
    for (int end = 0; end < s.length(); end++)
    {
        char c = s[end];
        if (lastIndex.count(c) && lastIndex[c] >= start)
        {
            start = lastIndex[c] + 1;
        }
        lastIndex[c] = end;
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}

int main()
{
    string s = "abcabcab";
    cout << "Maximum length: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}