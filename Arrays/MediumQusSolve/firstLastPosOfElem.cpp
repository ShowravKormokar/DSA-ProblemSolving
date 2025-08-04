// Leetcode problem 34 -> Find the first and last position of element in sorted array
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> nums, int target)
{
    vector<int> sr;
    int beg = 0, end = nums.size() - 1, f = -1, l = -1;
    // For first value find
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;

        if (nums[mid] >= target)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }

        if (nums[mid] == target)
        {
            f = mid;
        }
    }

    // For last value find
    beg = 0, end = nums.size() - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;

        if (nums[mid] <= target)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        if (nums[mid] == target)
        {
            l = mid;
        }
    }
    sr.push_back(f);
    sr.push_back(l);

    return sr;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = searchRange(nums, target);
    for (auto num : res)
    {
        cout << num << " ";
    }
    return 0;
}