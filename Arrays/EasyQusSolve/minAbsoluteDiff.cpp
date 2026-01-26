// Leetcode problem 1200. Minimum Absolute Difference
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        int minDiff = INT_MAX;

        sort(arr.begin(), arr.end());

        // Step 1: Find minimum difference
        for (int i = 1; i < arr.size(); i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        // Step 2: Collect pairs with min difference
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 2, 1, 3};

    auto result = sol.minimumAbsDifference(arr);

    for (auto &pair : result)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }
}

/*
TC: O(N log N) due to sorting the array.
SC: O(1) if we ignore the output storage.
*/
