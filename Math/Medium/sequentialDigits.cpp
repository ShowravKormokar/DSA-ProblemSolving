// Leetcode problem 1291 -> Sequential Digits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        queue<int> q{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

        while (!q.empty())
        {
            const int num = q.front();
            q.pop();
            if (num > high)
                return ans;
            if (low <= num && num <= high)
                ans.push_back(num);
            const int lastDigit = num % 10;
            if (lastDigit < 9)
                q.push(num * 10 + lastDigit + 1);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int low = 100, high = 300;
    vector<int> result = sol.sequentialDigits(low, high);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/*
TC: O(N), where N is the number of sequential digits generated.
SC: O(N), for storing the result and the queue.
*/