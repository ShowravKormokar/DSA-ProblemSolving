// Leetcode problem 2161 -> Partition Array According to Given Pivot
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans;

        for (const int num : nums)
            if (num < pivot)
                ans.push_back(num);

        for (const int num : nums)
            if (num == pivot)
                ans.push_back(num);

        for (const int num : nums)
            if (num > pivot)
                ans.push_back(num);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Partitioned Array: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}

/*
TC: O(n) -> We traverse the array three times, each traversal takes O(n) time.
SC: O(n) -> We are using an additional array 'ans' to store the partitioned elements, which can take up to O(n) space in the worst case (when all elements are less than, equal to, or greater than the pivot).
*/