// Leetcode problem 88 Merge Sorted Array

#include <bits/stdc++.h>
using namespace std;

void mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    cout << "Merge sorted array: ";
    for (auto val : nums1)
    {
        cout << val << " ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    mergeSortedArray(nums1, 3, nums2, 3);

    return 0;
}