// Leetcode problem 6 (String, Medium) -> Zigzag Conversion
#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
        return s;

    vector<string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        rows[currRow] += c;
        // Change direction if at top or bottom
        if (currRow == 0 || currRow == numRows - 1)
        {
            goingDown = !goingDown;
        }
        // Move up or down
        currRow += goingDown ? 1 : -1;
    }

    string result;
    for (string &row : rows)
    {
        result += row;
    }
    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << "The conversion is: " << convert(s, numRows) << endl; // Output: PAHNAPLSIIGYIR
    return 0;
}
/*
TC: O(n)
SC: O(n)
In this case TC: 2ms
*/