// Leetcode problem 326 -> Power of three
#include <bits/stdc++.h>
using namespace std;

bool powerOfThree(int n)
{
    // Way 01
    /*
    if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    */
    // Way 02
    double x = log10(n) / log10(3);
    return fabs(x - round(x)) < 1e-10;
}

int main()
{
    int n = 27;
    cout << "Power of three: " << powerOfThree(n) << endl; // Output: 1 [Means true, 3^n]
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/