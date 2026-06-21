// Leetcode problem 1833 -> Maximum Ice Cream Bars
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        ranges::sort(costs);

        for (int i = 0; i < costs.size(); ++i)
            if (coins >= costs[i])
                coins -= costs[i];
            else
                return i;

        return costs.size();
    }
};

int main()
{
    Solution sol;
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;

    cout << sol.maxIceCream(costs, coins) << endl;

    return 0;
}

/*
TC: O(n log n) -> due to sorting
SC: O(1) -> no extra space used
*/