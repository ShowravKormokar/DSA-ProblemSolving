// Leetcode problem 657 -> Robot Return to Origin
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int right = 0;
        int up = 0;

        for (const char move : moves)
        {
            switch (move)
            {
            case 'R':
                ++right;
                break;
            case 'L':
                --right;
                break;
            case 'U':
                ++up;
                break;
            case 'D':
                --up;
                break;
            }
        }

        return right == 0 && up == 0;
    }
};

int main()
{
    Solution sol;
    string moves = "UDLR";
    cout << boolalpha << sol.judgeCircle(moves) << endl; // Output: true
    return 0;
}

/*
TC: O(n) where n is the length of the moves string, as we need to iterate through each character in the string once.
SC: O(1) since we are using only a constant amount of extra space to store the counts of right and up moves.
*/