// Leetcode problem 67 -> Add Binary
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string a = "1010";
    string b = "1011";
    cout << sol.addBinary(a, b) << endl; // Output: "10101"
    return 0;
}

/*
TC: O(max(n, m)) where n and m are the lengths of the input strings a and b respectively.
SC: O(max(n, m)) for the output string ans, which in the worst case
*/