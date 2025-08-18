#include <bits/stdc++.h>
using namespace std;

vector<double> compute(double a, double b)
{
    vector<double> res = {a + b, a - b, b - a, a * b};
    if (fabs(b) > 1e-6)
        res.push_back(a / b);
    if (fabs(a) > 1e-6)
        res.push_back(b / a);
    return res;
}

// Forward declaration of solve
bool solve(vector<double> &nums);

bool judgePoint24(vector<int> &cards)
{
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
}

bool solve(vector<double> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return fabs(nums[0] - 24.0) < 1e-6;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<double> next;

            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                    next.push_back(nums[k]);
            }

            for (double val : compute(nums[i], nums[j]))
            {
                next.push_back(val);
                if (solve(next))
                    return true;
                next.pop_back();
            }
        }
    }
    return false;
}

int main()
{
    vector<int> cards = {4, 1, 8, 7};
    cout << "Result: " << judgePoint24(cards) << endl; // output: true
    return 0;
}

/*
TC:O(4!*operations)
SC: O(n)
*/
