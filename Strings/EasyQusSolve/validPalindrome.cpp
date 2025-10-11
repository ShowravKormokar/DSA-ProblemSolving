// Leetcode problem 125 -> Valid Palindrome
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            ++i, --j;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << "Is: " << sol.isPalindrome(s) << endl;
    return 0;
}