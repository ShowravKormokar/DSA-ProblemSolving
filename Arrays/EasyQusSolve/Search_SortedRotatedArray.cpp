#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int beg = 0, end = nums.size() - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[beg] <= nums[mid])
        {
            (target >= nums[beg] && target < nums[mid]) ? end = mid - 1 : beg = mid + 1;
        }
        else
        {
            (target > nums[mid] && target <= nums[end]) ? beg = mid + 1 : end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Index: " << search(nums, target) << endl;

    return 0;
}