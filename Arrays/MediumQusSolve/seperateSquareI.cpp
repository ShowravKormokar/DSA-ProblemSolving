// Leetcode problem 3453. Separate Squares I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        // Total area / 2
        const double halfArea =
            accumulate(squares.begin(), squares.end(), 0.0,
                       [](double sum, const vector<int> &square)
                       {
                           return sum + 1.0 * square[2] * square[2];
                       }) /
            2.0;

        // (y-coordinate, isStart, widthContribution)
        vector<tuple<int, bool, int>> events;

        for (const vector<int> &square : squares)
        {
            int y = square[1];
            int l = square[2];
            events.emplace_back(y, true, l);      // start
            events.emplace_back(y + l, false, l); // end
        }

        sort(events.begin(), events.end());

        double area = 0.0;
        int width = 0;
        int prevY = get<0>(events[0]);

        for (const auto &[y, isStart, l] : events)
        {
            double areaGain = 1.0 * width * (y - prevY);

            if (area + areaGain >= halfArea)
            {
                return prevY + (halfArea - area) / width;
            }

            area += areaGain;
            width += isStart ? l : -l;
            prevY = y;
        }

        return -1; // safety
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> squares = {
        {0, 0, 2}, // square with bottom-left (0,0), side 2
        {0, 2, 2}  // square with bottom-left (0,2), side 2
    };

    cout << fixed << setprecision(5)
         << "Separating Y-coordinate: "
         << sol.separateSquares(squares) << endl;

    return 0;
}

/*
TC: O(N log N) due to sorting the events.
SC: O(N) for storing the events.
*/