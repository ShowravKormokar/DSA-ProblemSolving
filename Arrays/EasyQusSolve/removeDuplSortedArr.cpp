// Leetcode problem 26 -> Remove duplicate from sorted array
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int index = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

// Requirement must remove duplicate element on the original array and return the size of after removing the duplicate

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << removeDuplicates(nums) << endl;
    return 0;
}