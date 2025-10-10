// Leetcode problem 3147 -> Taking maximum energy from mystic dungeon
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        vector<int> dp(n, 0);
        int maxEng = INT_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            int jmp = i + k;
            if (jmp < n)
            {
                dp[i] = energy[i] + dp[jmp];
            }
            else
            {
                dp[i] = energy[i];
            }
            maxEng = max(maxEng, dp[i]);
        }
        return maxEng;
    }
};

int main()
{
    Solution sol;
    vector<int> energy = {-2, -3, -1};
    int k = 2;
    cout << "Maximum Energy: " << sol.maximumEnergy(energy, k) << endl; // Output: -1
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/