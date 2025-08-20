// Leetcode problem 2348 -> Number of zero-filled subarrays
#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
    long long result = 0, count = 0;
    for (int x : nums)
    {
        if (x == 0)
        {
            count++;
            result += count;
        }
        else
        {
            count = 0;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};

    cout << "Result: " << zeroFilledSubarray(nums) << endl; // Output: 6

    return 0;
}

/*
TC: O(n)
SC: O(1)
*/