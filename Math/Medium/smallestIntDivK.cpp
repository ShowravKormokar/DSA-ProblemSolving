// Leetcode problem 1015 -> Smallest Integer Divisible by K
#include <bits/stdc++.h>
#include <bits/basic_string.h>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 10 != 1 && k % 10 != 3 && k % 10 != 7 && k % 10 != 9)
            return -1;

        unordered_set<int> seen;
        int n = 0;

        for (int length = 1; length <= k; ++length)
        {
            n = (n * 10 + 1) % k;
            if (n == 0)
                return length;
            if (seen.find(n) != seen.end())
                return -1;
            seen.insert(n);
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int k = 1;
    cout << "Result: " << sol.smallestRepunitDivByK(k) << endl;
    return 0;
}

/*
TC: O(K) -> In the worst case, we may need to check up to K different remainders.
SC: O(K) -> We use a set to store the remainders we have seen, which in the worst case can store up to K different remainders.
*/