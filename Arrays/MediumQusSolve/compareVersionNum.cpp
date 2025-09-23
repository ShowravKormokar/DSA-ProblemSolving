// Leetcode problem 165 -> Compare Version Numbers
#include <bits/stdc++.h>
using namespace std;

vector<int> splitStr(const string &version)
{
    vector<int> parts;
    stringstream ss(version);
    string token;

    while (getline(ss, token, '.'))
    {
        parts.push_back(stoi(token));
    }
    return parts;
}

int compareVersion(string version1, string version2)
{
    vector<int> v1 = splitStr(version1);
    vector<int> v2 = splitStr(version2);

    int n = max(v1.size(), v2.size());

    for (int i = 0; i < n; i++)
    {
        int num1 = (i < v1.size()) ? v1[i] : 0;
        int num2 = (i < v2.size()) ? v2[i] : 0;

        if (num1 < num2)
            return -1;
        if (num1 > num2)
            return 1;
    }

    return 0;
}

int main()
{
    string version1 = "1.01", version2 = "1.001";
    cout << "Result: " << compareVersion(version1, version2) << endl; // Output: 0
    return 0;
}

/*
TC: O(n+m)
SC: O(n+m)
*/