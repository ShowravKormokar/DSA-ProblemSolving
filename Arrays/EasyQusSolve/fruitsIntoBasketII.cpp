// Leetcode problem 3477 -> Fruits into basket II
#include <bits/stdc++.h>
using namespace std;

int numOfUnplacedFruit(vector<int> &fruits, vector<int> &basket)
{
    int n = fruits.size();
    int unplaced = n;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fruits[i] <= basket[j] && !visited[j])
            {
                visited[j] = true;
                --unplaced;
                break;
            }
        }
    }

    return unplaced;
}

int main()
{
    vector<int> fruits = {4, 2, 5};
    vector<int> basket = {3, 5, 4};

    cout << "Num of unplaced fruit(s): " << numOfUnplacedFruit(fruits, basket);

    return 0;
}

/*

*/