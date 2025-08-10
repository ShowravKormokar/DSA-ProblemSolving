// Leetcode problem 869 -> Recorded power of 2
#include <bits/stdc++.h>
using namespace std;

int counter(int n)
{
    int count = 0;

    for (; n > 0; n /= 10)
        count += pow(10, n % 10);

    return count;
}
bool reorderedPowerOf2(int n)
{
    int count = counter(n);

    for (int i = 0; i < 30; ++i)
        if (counter(1 << i) == count)
            return true;

    return false;
}

int main()
{
    int n = 1;
    cout << "Result: " << reorderedPowerOf2(n) << endl;
    return 0;
}