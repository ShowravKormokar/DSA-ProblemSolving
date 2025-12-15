// Leetcode problem 2110 -> Number of Smooth Descent Periods of a Stock
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long ans = 1;
        long long currLen = 1;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] == prices[i - 1] - 1)
            {
                currLen++;
            }
            else
            {
                currLen = 1;
            }
            ans += currLen;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3, 2, 1, 4};
    cout << "Result: " << sol.getDescentPeriods(prices) << endl;

    return 0;
}