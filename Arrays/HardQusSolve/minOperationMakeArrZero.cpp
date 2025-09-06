// Leetcode problem 3495 -> Minimum Operations to Make Array Elements Zero
#include <bits/stdc++.h>
using namespace std;

// Returns the number of operations required for [1, n].
long getOperations(int n)
{
    long res = 0;
    int ops = 0;
    for (int powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4)
    {
        const int l = powerOfFour;
        const int r = min(n, powerOfFour * 4 - 1);
        res += static_cast<long>(r - l + 1) * ++ops;
    }
    return res;
}

long long minOperations(vector<vector<int>> &queries)
{
    long ans = 0;
    for (const vector<int> &query : queries)
    {
        const int l = query[0];
        const int r = query[1];
        ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
    }
    return ans;
}

int main()
{
    vector<vector<int>> queries = {{1, 2}, {2, 4}};
    cout << "No. of min operation is : " << minOperations(queries) << endl; // Output: 3

    return 0;
}

/*
TC: O(q)
SC: O(1)
*/