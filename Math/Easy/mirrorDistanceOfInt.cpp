// Leetcode problem 3783 -> Mirror Distance of an Integer
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mirrorDistance(int n)
    {
        auto reverse = [](int x) -> int
        {
            int y = 0;
            for (; x; x /= 10)
            {
                y = y * 10 + x % 10;
            }
            return y;
        };
        return abs(n - reverse(n));
    }
};

int main()
{
    Solution sol;
    int n = 123;
    cout << sol.mirrorDistance(n) << endl; // Output: 198
    return 0;
}

/*
TC: O(log n) - The time complexity is logarithmic in relation to the number of digits in the input integer n, as we need to reverse the digits of n.
SC: O(1) - The space complexity is constant, as we are using a fixed amount of space to store the reversed integer and perform calculations, regardless of the size of n.
*/