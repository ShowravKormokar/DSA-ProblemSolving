// Leetcode problem 3613 -> Process String with Special Operations I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        string result;

        // Iterate through each character in the input string
        for (char c : s)
        {
            // If character is alphabetic, append it to result
            if (isalpha(c))
            {
                result += c;
            }
            // If character is '*', remove the last character from result
            else if (c == '*')
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
            // If character is '#', duplicate the current result string
            else if (c == '#')
            {
                result += result;
            }
            // If character is '%', reverse the entire result string
            else if (c == '%')
            {
                std::reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string s = "a*b#c%";
    string result = solution.processStr(s);
    cout << "Processed string: " << result << endl; // Output: "Processed string: cba"
    return 0;
}

/*
TC: O(n) - We iterate through the input string once, where n is the length of the string.
SC: O(n) - In the worst case, the result string can grow to the size of the input string due to the '#' operation, and we also use additional space for the result string.
*/