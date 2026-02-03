// Leetcode problem 3637 -> Trionic Array I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        vector<char> relations;

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            char relation;
            if (nums[i + 1] > nums[i])
                relation = '>';
            else if (nums[i + 1] < nums[i])
                relation = '<';
            else
                relation = '=';

            // If more than 3 relation changes, impossible
            if (relations.size() > 3)
                return false;

            // push relation only if it's different from last one
            if (relations.empty() || relations.back() != relation)
            {
                relations.push_back(relation);
            }
        }

        return relations == vector<char>{'>', '<', '>'};
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {5, 10, 5, 10, 5};
    if (obj.isTrionic(nums))
        cout << "The array is a Trionic Array." << endl;
    else
        cout << "The array is not a Trionic Array." << endl;
    return 0;
}

/*
TC: O(N) where N is the size of the input array nums.
SC: O(1) since the relations vector will hold at most 4 elements.
*/