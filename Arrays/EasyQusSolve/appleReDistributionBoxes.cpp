// Leetcode problem -> 074. Apple Redistribution into Boxes 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for (int i = 0; i < apple.size(); i++)
        {
            sum += apple[i];
        }

        int cnt = 0;

        for (auto cap : capacity)
        {
            if (sum <= 0)
                break;
            sum -= cap;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};

    cout << "Result: " << sol.minimumBoxes(apple, capacity) << endl;

    return 0;
}

// 6 - 5 =1