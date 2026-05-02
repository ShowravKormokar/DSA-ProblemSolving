// Leetcode probelm 788 -> Rotated Digits
#include <iostream>
#include <vector>

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int ans = 0;

        for (int i = 1; i <= n; ++i)
            if (isGoodNumber(i))
                ++ans;

        return ans;
    }

private:
    bool isGoodNumber(int i)
    {
        bool isRotated = false;

        for (const char c : to_string(i))
        {
            if (c == '0' || c == '1' || c == '8')
                continue;
            if (c == '2' || c == '5' || c == '6' || c == '9')
                isRotated = true;
            else
                return false;
        }

        return isRotated;
    }
};

int main()
{
    Solution sol;
    int n = 10;
    std::cout << sol.rotatedDigits(n) << std::endl; // Output: 4
    return 0;
}

/*
TC: O(n * log n) -> We iterate through all numbers from 1 to n, and for each number, we convert it to a string and check its digits. The conversion and checking take O(log n) time in the worst case (when n has multiple digits).
SC: O(log n) -> The space complexity is O(log n) due to the string representation of the number, which can have at most log10(n) digits. The additional space used for variables is constant, O(1).
*/