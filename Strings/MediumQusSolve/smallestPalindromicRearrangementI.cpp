// Leetcode problem 3517 -> Smallest Palindromic Rearrangement I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        const int n = s.length();
        const string sortedHalf = getSortedHalf(s);
        return sortedHalf + (n % 2 ? string(1, s[n / 2]) : "") +
               reversed(sortedHalf);
    }

private:
    string getSortedHalf(const string &s)
    {
        string half = s.substr(0, s.length() / 2);
        ranges::sort(half);
        return half;
    }

    string reversed(const string &s)
    {
        return {s.rbegin(), s.rend()};
    }
};

int main()
{
    Solution solution;
    string s = "bcaacb";
    cout << solution.smallestPalindrome(s) << endl; // Output: "abcba"
    return 0;
}

/*
TC: O(n log n) - Sorting the half of the string takes O(n log n) time.
SC: O(n) - The space used for storing the half of the string and the final palindrome is O(n).
*/