// Leetcode problem 1733 -> Minimum Number of People to Teach
#include <bits/stdc++.h>
using namespace std;

//----------- Hard to understand, need more practice-----------☠️❌🚨

int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
{
    int m = languages.size();
    vector<unordered_set<int>> knows(m + 1);

    for (int i = 0; i < m; i++)
    {
        for (int lang : languages[i])
        {
            knows[i + 1].insert(lang);
        }
    }

    unordered_set<int> problemPeople;
    for (auto &f : friendships)
    {
        int a = f[0], b = f[1];
        bool ok = false;
        for (int lang : knows[a])
        {
            if (knows[b].count(lang))
            {
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            problemPeople.insert(a);
            problemPeople.insert(b);
        }
    }

    if (problemPeople.empty())
        return 0;

    vector<int> count(n + 1, 0);
    for (int person : problemPeople)
    {
        for (int lang : knows[person])
        {
            count[lang]++;
        }
    }

    int ans = INT_MAX;
    for (int lang = 1; lang <= n; lang++)
    {
        ans = min(ans, (int)problemPeople.size() - count[lang]);
    }
    return ans;
}

int main()
{
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};

    cout << "Result: " << minimumTeachings(n, languages, friendships) << endl; // Output: 1
    return 0;
}

/*
TC: O(m * avg_languages_per_person + |friendships| * avg_languages)
SC: O(m * avg_languages)
*/