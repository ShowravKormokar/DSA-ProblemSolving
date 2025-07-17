// Leetcode problem 121 -> Best time to buy and sell stock
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = INT_MAX, maxProfit = 0;
    for (auto price : prices)
    {
        if (price < buy)
            buy = price;
        else
            maxProfit = max(maxProfit, price - buy);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Max profit is: " << maxProfit(prices) << endl;

    return 0;
}