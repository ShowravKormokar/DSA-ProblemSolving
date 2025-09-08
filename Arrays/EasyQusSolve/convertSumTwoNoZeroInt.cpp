// Leetcode problem 1317 -> Convert Integer to the Sum of Two No-Zero Integers
#include <bits/stdc++.h>
using namespace std;

bool noZero(int num)
{
    while (num > 0)
    {
        if (num % 10 == 0)
            return false;
        num /= 10;
    }
    return true;
}

vector<int> getNoZeroIntegers(int n)
{
    for (int a = 1; a < n; a++)
    {
        int b = n - a;
        if (noZero(a) && noZero(b))
        {
            return {a, b};
        }
    }
    return {};
}

int main()
{
    int n = 11;
    for (auto a : getNoZeroIntegers(n))
    {
        cout << a << " "; //Output: 2,9
    }
    cout << endl;
    return 0;
}

/*
TC: O(n × log(n))
SC: O(1)
*/