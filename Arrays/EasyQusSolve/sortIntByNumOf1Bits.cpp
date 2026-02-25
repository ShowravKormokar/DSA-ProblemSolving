// Leetcode problem 1356 -> Sort Integers by The Number of 1 Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int a, int b)
             {
            int bitA = __builtin_popcount(a);
            int bitB = __builtin_popcount(b);

            if(bitA == bitB)
            {
                return a<b; // Normal sort if bit equal
            }
            return bitA<bitB; }); // Otherwise bitwise sort
        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = s.sortByBits(arr);
    for (int i : ans)
    {
        cout << i << " "; // Output: 0 1 2 4 8 3 5 6 7
    }
    return 0;
}

/*
TC: O(n log n) -> Sorting takes n log n time
SC: O(1) -> No extra space is used
*/