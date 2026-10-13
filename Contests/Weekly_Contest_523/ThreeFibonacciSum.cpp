// Three Fibonacci Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool threeFibonacciSum(int n)
    {
        long long a = 0, b = 1;

        while (true)
        {
            long long c = a + b;
            long long sum = a + b + c;

            if (sum == n)
                return true;
            if (sum > n)
                return false;

            a = b;
            b = c;
        }
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << (sol.threeFibonacciSum(n) ? "true" : "false") << endl;
    return 0;
}