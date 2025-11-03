// Leetcode problem 1578 -> Minimum Time to Make Rope Colorful
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int maxTime = neededTime[0];
        int minTime = 0;
        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == colors[i - 1])
            {
                minTime += min(maxTime, neededTime[i]);
                maxTime = max(maxTime, neededTime[i]);
            }
            else
            {
                maxTime = neededTime[i];
            }
        }
        return minTime;
    }
};

int main()
{
    Solution sol;
    string colors = "aaabbbabbbb";
    vector<int> neededTime = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
    cout << "Min time: " << sol.minCost(colors, neededTime) << endl;
    return 0;
}