#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRotations(string s)
    {
        int current = 0;
        int totalRotations = 0;

        for (char c : s)
        {
            int digit = c - '0';
            int diff = abs(digit - current);

            int rotations = min(diff, 10 - diff);

            totalRotations += rotations;
            current = digit;
        }

        return totalRotations;
    }
};

int main()
{
    Solution solution;
    string s = "1234567890";
    int result = solution.minRotations(s);
    cout << "Minimum rotations to dial the number: " << result << endl;

    return 0;
}