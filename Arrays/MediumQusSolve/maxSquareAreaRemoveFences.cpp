// Leetcode problem 2975 -> Maximum Square Area by Removing Fences From a Field
#include <bits/stdc++.h>
using namespace std;

// Unsolved for now, complex to understand the approach, need more study🚨❌😥

class Solution
{
public:
    static constexpr long long kMod = 1000000007LL;
    int maximizeSquareArea(int m, int n, vector<int> &hFences,
                           vector<int> &vFences)
    {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        const unordered_set<int> hGaps = getGaps(hFences);
        const unordered_set<int> vGaps = getGaps(vFences);
        int maxGap = -1;

        for (const int hGap : hGaps)
            if (vGaps.count(hGap))
                maxGap = max(maxGap, hGap);

        if (maxGap == -1)
            return -1;
        long long area = (1LL * maxGap * maxGap) % kMod;
        return static_cast<int>(area);
    }

private:
    unordered_set<int> getGaps(const vector<int> &fences)
    {
        unordered_set<int> gaps;
        for (int i = 0; i < fences.size(); ++i)
            for (int j = 0; j < i; ++j)
                gaps.insert(fences[i] - fences[j]);
        return gaps;
    }
};

int main()
{
    Solution sol;
    vector<int> hFences = {2, 4, 5};
    vector<int> vFences = {2, 3};
    int m = 5, n = 4;
    cout << sol.maximizeSquareArea(m, n, hFences, vFences) << "\n";
    return 0;
}

/*
TC: O(H^2 + V^2) where H is the number of horizontal fences and V is the number of vertical fences.
SC: O(H^2 + V^2) for storing the gaps in unordered sets.
*/