// Leetcode problem 3479 -> Fruits into basket iii
#include <bits/stdc++.h>
using namespace std;

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = fruits.size();
    int unplaced = n;
    vector<bool> isVisited(n, false);

    for (auto fruit : fruits)
    {
        for (int i = 0; i < n; i++)
        {
            if (baskets[i] >= fruit && !isVisited[i])
            {
                isVisited[i] = true;
                unplaced--;
                break;
            }
        }
    }

    return unplaced;
}

/*
------------------ This problem is complex solution, need more knowledge. So this problem is unsolved.❌☠️
*/

int main()
{
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};

    cout << "Unplaced fruits: " << numOfUnplacedFruits(fruits, baskets) << endl;//Output wrong ans;

    return 0;
}