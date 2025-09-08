// Leetcode problem 20 -> Valid parentheses
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '(')
            stk.push(')');
        else if (c == '{')
            stk.push('}');
        else if (c == '[')
            stk.push(']');
        else
        {
            // It's a closing bracket
            if (stk.empty() || stk.top() != c)
                return false;
            stk.pop();
        }
    }

    return stk.empty(); // all matched properly
}

int main()
{
    string s = "()[]{}";
    cout << "Result: " << isValid(s) << endl; // Output: 1 (true)
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/