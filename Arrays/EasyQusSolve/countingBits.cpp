// Leetcode problem 338 -> Counting Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        // Way: 01
        // vector<int> ans(n + 1, 0);
        // for (int i = 1; i <= n; i++)
        // {
        //     int cnt = 0;
        //     int temp = i;
        //     while (temp)
        //     {
        //         temp = temp & (temp - 1);
        //         cnt++;
        //     }
        //     ans[i] = cnt;
        // }

        // return ans;
        // Way: 02
        vector<int> counter(n + 1);
        for (int i = 0; i <= n; i++)
        {
            counter[i] = __builtin_popcountll(i);
        }
        return counter;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    for (auto bit : sol.countBits(n))
    {
        cout << bit << ", ";
    }
    cout << endl;

    return 0;
}

/*
TC: O(n)
SC: O(1), O(n)
*/