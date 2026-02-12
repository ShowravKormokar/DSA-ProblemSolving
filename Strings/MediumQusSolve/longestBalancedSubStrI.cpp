// Leetcode problem 3713 -> Longest Balanced Substring I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int common = 0;
                bool ok = true;

                for (int f : freq)
                {
                    if (f > 0)
                    {
                        if (common == 0)
                            common = f;
                        else if (f != common)
                        {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aabbcc";
    cout << sol.longestBalanced(s) << endl; // Output: 6
    return 0;
}

/*
TC: O(n^2 * 26) -> O(n^2)
SC: O(26) -> O(1)
*/