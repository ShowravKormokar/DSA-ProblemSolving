// Leetcode problem 35 -> Search insert position
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    // Way 01
    //  int i = 0;
    //  for (; i < nums.size(); i++)
    //  {
    //      if (nums[i] == target)
    //      {
    //          return i;
    //      }
    //      else if (nums[i] > target)
    //      {
    //          break;
    //      }
    //  }
    //  return i;

    // way 02 (Most efficient TC= O(log n))
    int beg = 0, end = nums.size() - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << searchInsert(nums, target) << endl;
    return 0;
}