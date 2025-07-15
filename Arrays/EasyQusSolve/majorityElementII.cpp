// Leetcode 229 Majority Element II
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    int n = nums.size();

    for (auto num : nums)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (auto num : nums)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    vector<int> res;
    if (count1 > n / 3)
        res.push_back(candidate1);
    if (count2 > n / 3)
        res.push_back(candidate2);

    return res;
};

int main()
{
    vector<int> nums = {3, 2, 3};

    vector<int> res = majorityElement(nums);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}