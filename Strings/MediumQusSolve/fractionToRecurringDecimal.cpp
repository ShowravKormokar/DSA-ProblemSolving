// Leetcode problem 166 -> Fraction to Recurring Decimal
#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";

    string ans;

    // Step 1: Handle sign
    if ((numerator < 0) ^ (denominator < 0))
        ans += "-";

    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    // Step 2: Integer part
    ans += to_string(n / d);
    long long rem = n % d;
    if (rem == 0)
        return ans; // terminate

    ans += "."; // decimal point

    // Step 3: Fractional part
    unordered_map<long long, int> remainderIndex;
    while (rem != 0)
    {
        if (remainderIndex.count(rem))
        {
            ans.insert(remainderIndex[rem], "(");
            ans += ")";
            break;
        }

        remainderIndex[rem] = ans.size();
        rem *= 10;
        ans += to_string(rem / d);
        rem %= d;
    }

    return ans;
}

int main()
{
    int numerator = 4, denominator = 333;
    cout << "Result: " << fractionToDecimal(numerator, denominator) << endl; //Output: 0.(012)

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/