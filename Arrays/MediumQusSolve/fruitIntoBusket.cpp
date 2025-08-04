// Leetcode problem 904 -> Fruit into baskets
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> basket;
    int left = 0, maxFruit = 0;

    for (int right = 0; right < fruits.size(); right++)
    {
        basket[fruits[right]]++;

        while (basket.size() > 2)
        {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0)
            {
                basket.erase(fruits[left]);
            }
            left++;
        }
        maxFruit = max(maxFruit, right - left + 1);
    }
    return maxFruit;
}

int main()
{
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << totalFruit(fruits) << endl;
    return 0;
}
