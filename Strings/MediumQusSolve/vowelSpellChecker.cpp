// Leetcode problem 966 -> Vowel Spellchecker
#include <bits/stdc++.h>
using namespace std;

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
{
    unordered_set<string> exact(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caseInsensitive, vowelMasked;

    auto maskVowel = [](string s)
    {
        for (auto &c : s)
        {
            if (string("aeiou").find(tolower(c)) != string::npos)
                c = '*';
            else
                c = tolower(c);
        }
        return s;
    };

    for (auto &word : wordlist)
    {
        string lower;
        for (char c : word)
            lower += tolower(c);
        if (!caseInsensitive.count(lower))
            caseInsensitive[lower] = word;
        string mask = maskVowel(word);
        if (!vowelMasked.count(mask))
            vowelMasked[mask] = word;
    }

    vector<string> res;
    for (auto &q : queries)
    {
        if (exact.count(q))
            res.push_back(q);
        else
        {
            string lower;
            for (char c : q)
                lower += tolower(c);
            if (caseInsensitive.count(lower))
                res.push_back(caseInsensitive[lower]);
            else
            {
                string mask = maskVowel(q);
                if (vowelMasked.count(mask))
                    res.push_back(vowelMasked[mask]);
                else
                    res.push_back("");
            }
        }
    }
    return res;
}

int main()
{
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};

    for (auto res : spellchecker(wordlist, queries))
    {
        cout << res << ", "; // Output: kite, KiTe, KiTe, Hare, hare, KiTe, KiTe,
    }
    cout << endl;

    return 0;
}