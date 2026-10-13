// Prime Subset Selection I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> primeSubset(int n, int s)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        if (n >= 1)
            isPrime[1] = false;

        for (long long i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (long long j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> result;
        long long sum = 0;

        for (int p = 2; p <= n; p++)
        {
            if (!isPrime[p])
                continue;

            if (sum + p > s)
                break;

            sum += p;
            result.push_back(p);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n, s;
    cin >> n >> s;
    vector<int> result = sol.primeSubset(n, s);
    for (int p : result)
    {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}