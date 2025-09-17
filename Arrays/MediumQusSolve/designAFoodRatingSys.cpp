// Leetcode problem 2353 -> Design a Food Rating System
#include <bits/stdc++.h>
using namespace std;

// It's hard to understand ☠️🚨

class FoodRatings
{
private:
    // food -> (cuisine, rating)
    unordered_map<string, pair<string, int>> foodInfo;
    // cuisine -> ordered set of (-rating, food) for sorting
    unordered_map<string, set<pair<int, string>>> cuisineMap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        auto [cuisine, oldRating] = foodInfo[food];
        // Remove old entry
        cuisineMap[cuisine].erase({-oldRating, food});
        // Insert new entry
        cuisineMap[cuisine].insert({-newRating, food});
        // Update foodInfo
        foodInfo[food] = {cuisine, newRating};
    }

    string highestRated(string cuisine)
    {
        return cuisineMap[cuisine].begin()->second;
    }
};

int main()
{
    // Input values
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    // Create FoodRatings object
    FoodRatings fr(foods, cuisines, ratings);

    // Perform operations
    cout << fr.highestRated("korean") << endl;   // Expected: kimchi
    cout << fr.highestRated("japanese") << endl; // Expected: ramen
    fr.changeRating("sushi", 16);
    cout << fr.highestRated("japanese") << endl; // Expected: sushi
    fr.changeRating("ramen", 16);
    cout << fr.highestRated("japanese") << endl; // Expected: ramen (tie, but "ramen" < "sushi")

    return 0;
}

/*
TC: O(nlogn)
SC: O(1)
*/