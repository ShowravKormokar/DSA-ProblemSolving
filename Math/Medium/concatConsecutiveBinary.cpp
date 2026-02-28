// Leetcode problem 1680 -> Concatenation of Consecutive Binary Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        constexpr int kMod = 1'000'000'007;
        long ans = 0;

        for (int i = 1; i <= n; ++i)
            ans = ((ans << numberOfBits(i)) % kMod + i) % kMod;

        return ans;
    }

private:
    int numberOfBits(int n)
    {
        return log2(n) + 1;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    cout << sol.concatenatedBinary(n) << endl; // Output: 27
    return 0;
}

/*
TC: O(n log n) - We iterate through numbers from 1 to n, and for each number, we calculate the number of bits which takes O(log n) time.
SC: O(1) - We use a constant amount of extra space to store the answer and the temporary variables.
*/