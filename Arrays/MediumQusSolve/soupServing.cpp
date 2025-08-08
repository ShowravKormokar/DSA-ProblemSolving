// Leetcode problem 808 -> Soup Serving
#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> memo;

double dfs(int a, int b)
{
    if (a <= 0 && b <= 0)
        return 0.5;
    if (a <= 0)
        return 1.0;
    if (b <= 0)
        return 0.0;

    if (memo[a][b] > 0)
        return memo[a][b];

    memo[a][b] = 0.25 * (dfs(a - 4, b) +
                         dfs(a - 3, b - 1) +
                         dfs(a - 2, b - 2) +
                         dfs(a - 1, b - 3));

    return memo[a][b];
}

double soupServings(int n)
{
    if (n >= 5000)
        return 1.0;

    int n2 = (n + 24) / 25;
    memo = vector<vector<double>>(n + 1, vector<double>(n + 1, 0));
    return dfs(n2, n2);
}

int main()
{
    int n = 100;
    cout << "Result: " << soupServings(n) << endl;
    return 0;
}