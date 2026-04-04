// Leetcode problem 2075 -> Decode the Slanted Ciphertext
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        string ans;
        int cols = encodedText.size() / rows;
        for (int j = 0; j < cols; ++j)
        {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y)
            {
                ans += encodedText[x * cols + y];
            }
        }
        while (ans.size() && ans.back() == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string encodedText = "ch   ie   pr";
    int rows = 3;
    cout << sol.decodeCiphertext(encodedText, rows) << endl; // Output: "cipher"
    return 0;
}

/*
TC: O(n) where n is the length of the encodedText string.
SC: O(n) for the output string ans, which in the worst case can be of the same length as the input string encodedText.
*/