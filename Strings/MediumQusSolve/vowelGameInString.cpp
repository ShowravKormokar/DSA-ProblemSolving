// Leetcode problem 3227 -> Vowels Game in a String
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool doesAliceWin(string s)
{
    int k = 0;
    for (char c : s)
    {
        if (isVowel(c))
            k++;
    }
    if (k == 0)
        return false;
    return true;
}

int main()
{
    string s = "leetcoder";
    cout << "Result: " << doesAliceWin(s) << endl; // Output: true
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/