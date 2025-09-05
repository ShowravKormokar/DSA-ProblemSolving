// Leetcode problem 2749 -> Minimum Operations to Make the Integer Zero
#include <bits/stdc++.h>
using namespace std;

int makeTheIntegerZero(int num1, int num2)
{
    for (int k = 1; k <= 60; k++)
    {
        long long target = 1LL * num1 - 1LL * num2 * k;
        if (target < k)
            break;
        if (__builtin_popcountll(target) <= k && k <= target)
            return k;
    }
    return -1;
}

int main()
{
    int num1 = 3, num2 = -2;
    cout << "Result: " << makeTheIntegerZero(num1, num2) << endl; // Output: 3
    return 0;
}

/*
TC: O(60)
SC: O(1)
*/