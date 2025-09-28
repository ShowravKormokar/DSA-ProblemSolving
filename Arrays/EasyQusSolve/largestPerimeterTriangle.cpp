// Leetcode problem 976 -> Largest Perimeter Triangle
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>()); // sort descending

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            if (b + c > a)
            {
                return a + b + c; // first valid triple gives largest perimeter
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 1, 2};
    cout << "Largest Perimeter: " << sol.largestPerimeter(nums1) << endl; // Output: 5

    vector<int> nums2 = {1, 2, 1};
    cout << "Largest Perimeter: " << sol.largestPerimeter(nums2) << endl; // Output: 0

    vector<int> nums3 = {3, 2, 3, 4};
    cout << "Largest Perimeter: " << sol.largestPerimeter(nums3) << endl; // Output: 10

    return 0;
}

/*
TC: O(n*log*n)
XC: O(1)
*/