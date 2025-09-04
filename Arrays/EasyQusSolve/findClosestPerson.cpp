// Leetcode problem 3516 -> Find closest person
#include <bits/stdc++.h>
using namespace std;

int findClosest(int x, int y, int z)
{
    int fPer = abs(z - x);
    int sPer = abs(z - y);

    if (fPer == sPer)
    {
        return 0;
    }
    else if (fPer < sPer)
    {
        return 1;
    }

    return 2;
}

int main()
{
    int x = 2, y = 7, z = 4;
    cout << "The closest person is: " << findClosest(x, y, z) << endl; // Output: 1 [Explanation: 1st person is x, who closest to the z just 2 steps, while y need 3 steps]
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/