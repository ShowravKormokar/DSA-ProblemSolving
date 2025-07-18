// Leetcode 50 problem -> Pow(x,n)
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    long long power = n;
    if (power < 0)
    {
        x = 1 / x;
        power = -power;
    }
    double res = 1.0;
    while (power > 0)
    {
        if (power & 1) // for odd number
            res *= x;

        x *= x;
        power >>= 1;
    }

    return res;
}

int main()
{
    double x = 2.0;
    int n = -2;

    cout << "Pow x= " << x << " to the power n= " << n << ", Result: " << myPow(x, n) << endl;
    return 0;
}