// Leetcode 75 problem -> Sort Color
#include <bits/stdc++.h>
using namespace std;

void sortColor(vector<int> &nums)
{
    // Dutch flag national algorithm
    int low = 0, mid = 0, heigh = nums.size() - 1;

    while (mid <= heigh)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[heigh]);
            heigh--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColor(nums);
    for (auto num : nums)
        cout << num << " "; //Output: 0 0 1 1 2 2
    return 0;
}