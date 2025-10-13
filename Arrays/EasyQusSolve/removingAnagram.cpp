// Leetcode problem 2273 -> Find Resultant Array After Removing Anagrams
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;

        for (int i = 0; i < words.size();)
        {
            int j = i + 1;
            while (j < words.size() && isAnagram(words[i], words[j]))
                ++j;
            ans.push_back(words[i]);
            i = j;
        }

        return ans;
    }

private:
    bool isAnagram(const string &a, const string &b)
    {
        if (a.length() != b.length())
            return false;

        vector<int> count(26);

        for (const char c : a)
            ++count[c - 'a'];

        for (const char c : b)
            --count[c - 'a'];
        // ranges work C++🚨
        return ranges::all_of(count, [](const int c)
                              { return c == 0; });
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    for (auto word : sol.removeAnagrams(words))
    {
        cout << word << " ";
    }
    cout << endl;
    // cout << sol.removeAnagrams(words) << endl;
    return 0;
}

/*
TC: O(sum of words[i])
SC: O(sum of words[i])
*/