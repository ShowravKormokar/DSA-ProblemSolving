// Leetcode problem 2785 -> Sort Vowels in a String
#include <bits/stdc++.h>
using namespace std;

string sortVowels(string s)
{
    string vowels = "aeiouAEIOU";
    unordered_set<char> vList(vowels.begin(), vowels.end());
    vector<char> vl;

    for (auto c : s)
    {
        if (vList.count(c))
            vl.push_back(c);
    }

    sort(vl.begin(), vl.end());

    int idx = 0;
    for (auto &c : s)
    {
        if (vList.count(c))
            c = vl[idx++];
    }

    return s;
}

int main()
{
    string s = "lEetcOde";

    cout << "Sorted string: " << sortVowels(s) << endl;

    return 0;
}

/*
TC: O(n*log*n)
SC: O(n)
*/