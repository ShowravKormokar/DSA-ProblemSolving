// Leetcode problem 1518 -> Water bottles
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;

        while (numBottles >= numExchange)
        {
            ans += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int numBottles = 9, numExchange = 3;
    cout << "Maximum num of bottles: " << sol.numWaterBottles(numBottles, numExchange) << endl; // Output: 13
    return 0;
}

/*
TC: O(log numBottles)
SC: O(1)
*/