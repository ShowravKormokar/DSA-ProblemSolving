// Leetcode problem 1912 -> Design Movie Rental System
#include <bits/stdc++.h>
using namespace std;

// Very hard to understand and implementation, need more study to solve it ☠️🚨❌

class MovieRentingSystem
{
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;
        if (available.count(movie))
        {
            auto &s = available[movie];
            for (auto it = s.begin(); it != s.end() && result.size() < 5; ++it)
            {
                result.push_back(it->second);
            }
        }
        return result;
    }

    void rent(int shop, int movie)
    {
        int price = priceMap[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;
        for (auto it = rented.begin(); it != rented.end() && result.size() < 5; ++it)
        {
            result.push_back({it->shop, it->movie});
        }
        return result;
    }

private:
    struct RentedMovie
    {
        int price, shop, movie;
        bool operator<(const RentedMovie &other) const
        {
            if (price != other.price)
                return price < other.price;
            if (shop != other.shop)
                return shop < other.shop;
            return movie < other.movie;
        }
    };

    map<pair<int, int>, int> priceMap;
    unordered_map<int, set<pair<int, int>>> available;
    set<RentedMovie> rented;
};

int main()
{
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};

    MovieRentingSystem system(3, entries);

    auto res1 = system.search(1);
    cout << "search(1): ";
    for (int x : res1)
        cout << x << " ";
    cout << "\n";

    system.rent(0, 1);

    auto res2 = system.search(1);
    cout << "search(1) after renting (0,1): ";
    for (int x : res2)
        cout << x << " ";
    cout << "\n";

    auto rep1 = system.report();
    cout << "report(): ";
    for (auto &v : rep1)
        cout << "(" << v[0] << "," << v[1] << ") ";
    cout << "\n";

    system.drop(0, 1);

    auto rep2 = system.report();
    cout << "report() after drop: ";
    for (auto &v : rep2)
        cout << "(" << v[0] << "," << v[1] << ") ";
    cout << "\n";

    return 0;
}