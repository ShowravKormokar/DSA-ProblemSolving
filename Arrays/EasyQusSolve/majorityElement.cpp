// Leetcode 169 Majority Element

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    // Using Boyer-Moore Voting Algorithm (O(n) Time, O(1) Space)
    int count = 0, candidate = 0;
    for (auto num : nums)
    {
        if (count == 0)
            candidate = num;

        if (num == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout << "Majority element is: " << majorityElement(nums) << endl;
    return 0;
}