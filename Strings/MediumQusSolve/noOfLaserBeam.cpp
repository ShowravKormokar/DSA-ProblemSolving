// Leetcode problem 2125 -> Number of laser beam in the bank
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prev = 0;
        int totalBeam = 0;

        for (string row : bank)
        {
            int curr = count(row.begin(), row.end(), '1');
            if (curr == 0)
                continue;
            totalBeam += curr * prev;
            prev = curr;
        }
        return totalBeam;
    }
};

int main()
{
    Solution sol;
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << "Result: " << sol.numberOfBeams(bank) << endl;
    return 0;
}

/*
TC: O(m*n)
SC: O(1)
*/