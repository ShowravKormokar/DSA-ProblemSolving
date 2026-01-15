// Leetcode problem 2943. -> Maximize Area of Square Hole in Grid
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                               vector<int> &vBars)
    {
        const int gap = min(maxContinousGap(hBars), maxContinousGap(vBars));
        return gap * gap;
    }

private:
    int maxContinousGap(vector<int> &bars)
    {
        int res = 2;
        int runningGap = 2;
        sort(bars.begin(), bars.end());
        for (int i = 1; i < bars.size(); ++i)
        {
            runningGap = bars[i] == bars[i - 1] + 1 ? runningGap + 1 : 2;
            res = max(res, runningGap);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int n = 5, m = 5;
    vector<int> hBars = {2, 3};
    vector<int> vBars = {2, 3};
    cout << sol.maximizeSquareHoleArea(n, m, hBars, vBars) << endl; // Output: 9
    return 0;
}

/*
TC: O(B log B + C log C) where B and C are the sizes of hBars and vBars respectively.
SC: O(1) as we are using only a constant amount of extra space.
*/