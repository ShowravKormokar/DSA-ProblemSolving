// Leetcode problem 3484 -> Design Spreadsheet
#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
public:
    Spreadsheet(int rows)
    {
        (void)rows; // unused in this simple implementation
    }

    void setCell(string cell, int value)
    {
        spreadsheet[cell] = value;
    }

    void resetCell(string cell)
    {
        spreadsheet[cell] = 0;
    }

    int getValue(string formula)
    {
        const int i = formula.find('+');
        // formula assumed to be like "=A1+B1" or "=A1+20" (leading '=')
        return getToken(formula.substr(1, i - 1)) + getToken(formula.substr(i + 1));
    }

private:
    unordered_map<string, int> spreadsheet;

    int getToken(const string &token)
    {
        if (token.empty())
            return 0;
        if (isdigit((unsigned char)token[0]))
        {
            return stoi(token);
        }
        else
        {
            // Use find() for portability to pre-C++20 standards
            auto it = spreadsheet.find(token);
            return (it != spreadsheet.end()) ? it->second : 0;
        }
    }
};

int main()
{
    Spreadsheet sheet(3);

    // Set some values in cells
    sheet.setCell("A1", 5);
    sheet.setCell("B1", 10);

    cout << "Value of A1: " << sheet.getValue("=A1+0") << endl; // 5
    cout << "Value of B1: " << sheet.getValue("=B1+0") << endl; // 10

    // Formula: A1 + B1
    cout << "Value of =A1+B1: " << sheet.getValue("=A1+B1") << endl; // 15

    // Formula: A1 + number
    cout << "Value of =A1+20: " << sheet.getValue("=A1+20") << endl; // 25

    // Reset A1
    sheet.resetCell("A1");
    cout << "After reset A1, Value of =A1+B1: " << sheet.getValue("=A1+B1") << endl; // 10

    return 0;
}

/*
TC: O(1)
SC: O(∣setCell(cell: str, value: int)∣)
*/