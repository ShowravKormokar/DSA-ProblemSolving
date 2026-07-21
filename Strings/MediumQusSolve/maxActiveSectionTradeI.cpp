// Leetcode problem 3499 -> Maximum Active Section Trade I
#include <bits/stdc++.h>
using namespace std;

#include <ranges>

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        vector<int> zeroGroupLengths;
        int maxZeroMerge = 0;

        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '0')
            {
                if (i > 0 && s[i - 1] == '0')
                    ++zeroGroupLengths.back();
                else
                    zeroGroupLengths.push_back(1);
            }

        for (const auto &[a, b] : zeroGroupLengths | views::pairwise)
            maxZeroMerge = max(maxZeroMerge, a + b);

        return ranges::count(s, '1') + maxZeroMerge;
    }
};

int main()
{
    Solution sol;
    string s = "110001111000011";
    int result = sol.maxActiveSectionsAfterTrade(s);
    cout << "Maximum active sections after trade: " << result << endl;

    return 0;
}

/*
TC: O(n) where n is the length of the string s.
SC: O(k) where k is the number of groups of '0's in the string s. In the worst case, k can be O(n) if the string consists of alternating '0's and '1's.
*/