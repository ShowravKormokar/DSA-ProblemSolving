// Leetcode problem 7 -> Reverse Integer
#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;
        if (rev > INT_MAX || rev < INT_MIN)
            return 0;
    }
    return (int)rev;
};

int main()
{
    int x = 123;
    cout << "Reverse Number: " << reverse(x) << endl;
    return 0;
}