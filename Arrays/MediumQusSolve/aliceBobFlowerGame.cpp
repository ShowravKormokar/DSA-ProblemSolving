// Leetcode problem 3021 -> Alice and Bob Playing Flower Game
#include <bits/stdc++.h>
using namespace std;

long long flowerGame(int n, int m)
{
    const int xEven = n / 2;
    const int yEven = m / 2;
    const int xOdd = (n + 1) / 2;
    const int yOdd = (m + 1) / 2;
    return static_cast<long>(xEven) * yOdd + static_cast<long>(yEven) * xOdd;
}

int main()
{
    int n = 3, m = 2;
    cout << "Result: " << flowerGame(n, m) << endl; // Output: 3
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/