// Leetcode problem 1323 -> Maximum 69 Number
#include <bits/stdc++.h>
using namespace std;

int maximum69Number(int num)
{
    string ans = to_string(num);

    for (char &c : ans)
    {
        if (c == '6')
        {
            c = '9';
            break;
        }
    }
    return stoi(ans);
}

int main()
{
    int num = 9669;
    cout << "Result is: " << maximum69Number(num) << endl; // Output: 9969
    return 0;
}

/*
TC: O(log n)
SC: O(log n)
*/