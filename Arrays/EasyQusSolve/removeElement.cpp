// Leetcode problem 27 -> Remove element
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    if (nums.empty())
        return 0;

    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << removeElement(nums, val) << endl;
    return 0;
}