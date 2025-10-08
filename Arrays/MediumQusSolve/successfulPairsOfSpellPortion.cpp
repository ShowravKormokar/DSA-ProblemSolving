// Leetcode problem 2300 -> Successfull Pairs of Spells and Potions
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end()); // Sort potions for binary search
        vector<int> res;
        int m = potions.size();

        for (long long spell : spells)
        {
            // Minimum potion needed to reach success
            long long minPotion = (success + spell - 1) / spell; // ceil(success / spell)

            // Find first potion >= minPotion using binary search
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);

            // Count of successful potions
            int count = potions.end() - it;
            res.push_back(count);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> ans = sol.successfulPairs(spells, potions, success);

    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i + 1 < ans.size() ? ", " : ""); //Output: 4, 0, 3
    cout << "]" << endl;

    return 0;
}

/*
TC: O(n* log*m)
SC: O(1)
*/