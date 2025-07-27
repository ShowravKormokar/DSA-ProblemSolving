// Leetcode 2210 problem -> Count Hills and Valleys in an array
#include <bits/stdc++.h>
using namespace std;

int countHillValley(vector<int> &nums)
{
    // Remove duplicate value
    vector<int> vec;
    vec.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            vec.push_back(nums[i]);
        }
    }

    int count = 0;
    for (int i = 1; i < vec.size() - 1; i++)
    {
        if ((vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) || (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]))
            count++;
    }
    return count;
}

int main()
{
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << countHillValley(nums) << endl;
    return 0;
}