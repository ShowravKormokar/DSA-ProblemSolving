// Leetcode problem 1304 -> Find N Unique Integers Sum up to Zero
#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = i * 2 - n + 1;
    }
    return res;
}

int main()
{
    int n = 5;
    vector<int> res = sumZero(n);
    for (auto r : res)
    {
        cout << r << " "; // Output: -4 -2 0 2 4
    }
    cout << endl;
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/