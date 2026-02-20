// Leetcode problem 761 -> Special Binary String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        vector<string> subs;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                count++;
            else
                count--;

            if (count == 0)
            {
                // Inside recursion
                string inner = s.substr(start + 1, i - start - 1);
                subs.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort descending order
        sort(subs.begin(), subs.end(), greater<string>());

        string result = "";
        for (auto &str : subs)
            result += str;

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "11011000";
    cout << sol.makeLargestSpecial(s) << endl; // Output: "11100100"
    return 0;
}

/*
TC: O(n log n) - sorting takes O(n log n) and we are doing it for each substring, but the total length of all substrings is O(n).
SC: O(n) - for storing the substrings and the recursion stack.
*/