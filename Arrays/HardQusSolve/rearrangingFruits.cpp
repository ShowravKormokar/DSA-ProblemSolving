// Leetcode problem 2561 -> Rearranging Fruits
#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    // Store frequency
    map<int, int> freq;

    // Count frequency
    for (auto x : basket1)
        freq[x]++;
    for (auto x : basket2)
        freq[x]--;

    vector<int> extra;
    for (auto &[fruit, count] : freq)
    {
        if (count % 2 != 0)
            return -1;
        for (int i = 0; i < abs(count) / 2; i++)
        {
            extra.push_back(fruit);
        }
    }

    if (empty(extra))
        return 0;

    sort(extra.begin(), extra.end());

    int n = extra.size();
    int minFruit = min(*min_element(basket1.begin(), basket2.end()), *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;

    for (int i = 0; i < n / 2; i++)
    {
        cost += min(extra[i], 2 * minFruit);
    }

    return cost;
}

int main()
{
    vector<int> basket1 = {4, 2, 2, 2};
    vector<int> basket2 = {1, 4, 1, 2};

    cout << "Minimum cost is: " << minCost(basket1, basket2) << endl;

    return 0;
}