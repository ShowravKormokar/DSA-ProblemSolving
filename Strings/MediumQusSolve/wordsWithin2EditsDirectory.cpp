// Leetcode probelm 2452 -> Words Within Two Edits of Dictionary
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries,
                                vector<string> &dictionary)
    {
        vector<string> ans;

        for (const string &query : queries)
        {
            for (const string &word : dictionary)
            {
                if (inner_product(query.begin(), query.end(), word.begin(), 0, plus<>(),
                                  not_equal_to<char>()) < 3)
                {
                    ans.push_back(query);
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"wood", "joke", "moat"};
    vector<string> ans = sol.twoEditWords(queries, dictionary);

    for (const string &word : ans)
        cout << word << " ";
    cout << endl;

    return 0;
}

/*
TC: O(n * m) where n is the number of queries and m is the number of words in the dictionary.
SC: O(n) for the answer vector.
*/