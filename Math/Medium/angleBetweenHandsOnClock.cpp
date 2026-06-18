// Leetcode problem 1344 -> Angle Between Hands of a Clock
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double hourAngle = (hour % 12) * 30 + (minutes / 60.0) * 30;
        double minuteAngle = minutes * 6;

        double angle = abs(hourAngle - minuteAngle);
        return min(angle, 360 - angle);
    }
};

int main()
{
    Solution sol;
    int hour = 3, minutes = 15;
    cout << "Angle between hands of the clock at " << hour << ":" << minutes << " is " << sol.angleClock(hour, minutes) << " degrees." << endl;
    return 0;
}

/*
TC: O(1) -> The calculations are done in constant time.
SC: O(1) -> No additional space is used, only a few variables for calculations.
*/