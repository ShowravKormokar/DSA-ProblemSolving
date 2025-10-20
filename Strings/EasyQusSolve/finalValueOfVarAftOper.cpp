// Leetcode problem 2011 -> Final value of variable after performing operation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans = 0;
        for (const string &op : operations)
            ans += op[1] == '+' ? 1 : -1;

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> operations = {"--X", "X++", "X++"};
    cout << "Result: " << sol.finalValueAfterOperations(operations) << endl;//Output: 1
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/