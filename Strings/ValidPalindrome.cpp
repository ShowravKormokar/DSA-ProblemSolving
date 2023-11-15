#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int length = str.length() - 1;

    for (int i = 0; i < length; i++)
    {
        if (isalnum(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else
        {
            str.erase(i, 1);
            length--;
            i--;
        }
    }

    string str2 = str;
    reverse(str2.begin(), str2.end());

    (str == str2) ? cout << "String is Palindromic\n" : cout << "Not Palindromic\n";
}