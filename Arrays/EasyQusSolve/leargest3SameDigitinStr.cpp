// Leetcode problem 2264 -> Largest 3 same digit in string
#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    string ans = "";
    for (int i = 0; i + 2 < num.size(); i++)
    {
        if (num[i] == num[i + 1] && num[i] == num[i + 2])
        {
            string temp = num.substr(i, 3);
            if (temp > ans)
                ans = temp;
        }
    }
    return ans;
}

int main()
{
    string num = "6777133339";
    cout << "Largest good integer: " << largestGoodInteger(num) << endl; // Output: 777
    return 0;
}

/*
TC: O(n)
SC: O(1)
*/