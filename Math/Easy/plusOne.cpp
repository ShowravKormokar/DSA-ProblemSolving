// Leetcode problem 66 -> Plus One
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        for (int i = n; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If all digits are 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> digits = {9};

    cout << "Results: ";
    for (auto digit : sol.plusOne(digits))
    {
        cout << digit << " "; // Output: 1, 0
    }
    cout << endl;

    return 0;
}

/*
TC: O(n)
SC: O(1)
*/