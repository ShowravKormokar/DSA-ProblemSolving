// Leetcode problem 1461 -> Check If a String Contains All Binary Codes of Size K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        const int n = 1 << k;
        if (s.length() < n)
            return false;

        // used[i] := true if i is a substring of `s`
        vector<bool> used(n);

        int window = k == 1 ? 0 : stoi(s.substr(0, k - 1), nullptr, 2);
        for (int i = k - 1; i < s.length(); ++i)
        {
            // Include the s[i].
            window = (window << 1) + (s[i] - '0');
            // Discard the s[i - k].
            window &= n - 1;
            used[window] = true;
        }

        return all_of(used.begin(), used.end(), [](bool u)
                      { return u; });
    }
};

int main()
{
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << sol.hasAllCodes(s, k) << endl; // Output: true
    return 0;
}

/*
TC: O(n), where n is the length of the input string `s`. We iterate through the string once to check for all binary codes of size `k`.
SC: O(2^k), where k is the size of the binary codes we want to check. We use a boolean vector of size 2^k to keep track of which binary codes have been seen in the string.
*/