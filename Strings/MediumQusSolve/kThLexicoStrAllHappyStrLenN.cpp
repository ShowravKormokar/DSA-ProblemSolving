// Leetcode problem 1415 -> The k-th Lexicographical String of All Happy Strings of Length n
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        const unordered_map<char, string> nextLetters{
            {'a', "bc"}, {'b', "ac"}, {'c', "ab"}};
        queue<string> q{{{"a", "b", "c"}}};

        while (q.front().length() != n)
        {
            const string u = q.front();
            q.pop();
            for (const char nextLetter : nextLetters.at(u.back()))
                q.push(u + nextLetter);
        }

        if (q.size() < k)
            return "";

        for (int i = 0; i < k - 1; ++i)
            q.pop();
        return q.front();
    }
};

int main()
{
    Solution sol;
    int n = 3, k = 9;
    cout << sol.getHappyString(n, k) << endl;
    return 0;
}

/*
TC: O(3^n) -> We can have at most 3^n happy strings of length n.
SC: O(3^n) -> We can have at most 3^n happy strings of length n.
*/