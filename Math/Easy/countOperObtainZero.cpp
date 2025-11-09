// Leetcode problem -> 2169. Count Operations to Obtain Zero
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;
        while (num1 != 0 && num2 != 0)
        {
            if (num1 >= num2)
            {
                num1 = num1 - num2;
            }
            else
            {
                num2 = num2 - num1;
            }
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    int num1 = 5, num2 = 3;
    cout << "Number of operations to obtain zero: " << sol.countOperations(num1, num2) << endl; // Output: 4
    return 0;
}

/*
TC: O(log(min(num1, num2))) - In each operation, the larger number is reduced by at least the smaller number, leading to a logarithmic number of operations in relation to the smaller number.
SC: O(1) - We are using a constant amount of space for the counter and a few variables, regardless of the input size.
*/