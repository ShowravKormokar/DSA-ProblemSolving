// Leetcode problem 3513 -> Number of Unique XOR Triplets I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        const int n = nums.size();
        if (n < 3)
            return n;
        return 1 << (static_cast<int>(log2(n)) + 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = sol.uniqueXorTriplets(nums);
    cout << "Number of unique XOR triplets: " << result << endl;

    return 0;
}

/*
TC: O(1) since the computation of the number of unique XOR triplets is done in constant time.
SC: O(1) since no additional space is used that scales with the input size.
*/
