// Leetcode problem 3075 -> Maximize Happiness of Selected Children
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long ans = 0;
        int decremented = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        for (int i = 0; i < k; ++i)
        {
            ans += max(0, happiness[i] - decremented);
            ++decremented;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> happiness = {1, 2, 3};
    int k = 2;
    cout << "Result: " << sol.maximumHappinessSum(happiness, k) << endl;
    return 0;
}

/*
TC: O(sort)
SC: O(sort)
*/