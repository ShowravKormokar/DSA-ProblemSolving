// Leetcode problem 3100 -> Water Bottles II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int empties = numBottles;
        int required = numExchange;
        int total = numBottles;

        // Greedy simulation, minimal operations
        while (empties >= required)
        {
            empties -= required - 1; // directly replace: spend required, get 1 back
            total++;
            required++;
        }
        return total;
    }
};

int main()
{
    Solution sol;
    int numBottles = 20, numExchange = 1;
    cout << "Max bottle drunk: " << sol.maxBottlesDrunk(numBottles, numExchange) << endl;
    return 0;
}

/*
TC: O(numBottles)
SC: O(1)
*/