// Leetcode 15 problem -> Three Sum
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    // Sort array
    sort(nums.begin(), nums.end());
    // For store result
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // Avoid duplicate i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) // Avoid duplicate from left
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) // Avoid duplicate from right
                {
                    right--;
                }
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    auto ans = threeSum(nums);

    for (auto row : ans)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << ", " << endl;
    }
    return 0;
}