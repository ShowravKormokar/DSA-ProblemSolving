// Leetcode problem 3751 -> Total Waviness of Numbers in Range I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int ans = 0;
        for (int x = num1; x <= num2; x++)
        {
            ans += f(x);
        }
        return ans;
    }

    int f(int x)
    {
        int nums[20], m = 0;
        while (x > 0)
        {
            nums[m++] = x % 10;
            x /= 10;
        }
        if (m < 3)
        {
            return 0;
        }
        int s = 0;
        for (int i = 1; i < m - 1; i++)
        {
            if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) || (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]))
            {
                s++;
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    int num1 = 100, num2 = 200;
    cout << sol.totalWaviness(num1, num2) << endl;
    return 0;
}

/*
TC: O((num2 - num1) * log(num2)) -> For each number in the range, we calculate its waviness which takes O(log(num2)) time.
SC: O(log(num2)) -> The space used to store the digits of the number in the function f is proportional to the number of digits, which is O(log(num2)).
*/
