// Leetcode problem 3014. Minimum Number of Pushes to Type Word I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0;
        vector<int> count(26);

        for (const char c : word)
            ++count[c - 'a'];

        ranges::sort(count, greater<>());

        for (int i = 0; i < 26; ++i)
            ans += count[i] * (i / 8 + 1);

        return ans;
    }
};

int main()
{
    Solution solution;
    string word = "hello";
    int result = solution.minimumPushes(word);
    cout << "Minimum number of pushes to type the word '" << word << "': " << result << endl;
    return 0;
}

/*
TC: O(nlogn) where n is the length of the word
SC: O(1) since the count vector has a fixed size of 26
*/