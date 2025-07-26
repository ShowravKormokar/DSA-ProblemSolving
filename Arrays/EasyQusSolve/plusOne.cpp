// Leetcode problem 66 -> Plus One
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits; // No carry, Done!
        }
        digits[i] = 0; // Carry generated
    }

    // If all digits are 9
    digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    vector<int> digits = {9};
    digits = plusOne(digits);

    for (auto digit : digits)
    {
        cout << digit << " ";
    }
    return 0;
}