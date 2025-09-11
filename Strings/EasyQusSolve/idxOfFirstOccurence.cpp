// Leetcode problem 28 -> Find the Index of the First Occurrence in a String
#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        if (haystack.substr(i, m) == needle)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string haystack = "sadbutsad", needle = "sad";
    cout << "Result: " << strStr(haystack, needle) << endl; // Output: 0
    return 0;
}
/*
TC: O((n-m+1) * m)
SC: O(1)
*/