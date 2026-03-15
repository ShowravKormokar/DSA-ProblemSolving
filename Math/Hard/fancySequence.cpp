// Leetcode problem 1622 -> Fancy Sequence
#include <bits/stdc++.h>
using namespace std;

class Fancy
{
public:
    void append(int val)
    {
        const long x = (val - b + kMod) % kMod;
        vals.push_back(x * modPow(a, kMod - 2) % kMod);
    }

    void addAll(int inc)
    {
        b = (b + inc) % kMod;
    }

    void multAll(int m)
    {
        a = (a * m) % kMod;
        b = (b * m) % kMod;
    }

    int getIndex(int idx)
    {
        return idx >= vals.size() ? -1 : (a * vals[idx] + b) % kMod;
    }

private:
    static constexpr int kMod = 1000000007;

    vector<unsigned long> vals;
    unsigned long a = 1;
    unsigned long b = 0;

    long modPow(long x, long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * modPow(x % kMod, (n - 1)) % kMod;
        return modPow(x * x % kMod, (n / 2)) % kMod;
    }
};

int main()
{
    Fancy fancy;

    fancy.append(2);  // [2]
    fancy.addAll(3);  // [5]
    fancy.append(7);  // [5,7]
    fancy.multAll(2); // [10,14]

    cout << fancy.getIndex(0) << endl; // 10

    fancy.addAll(3);  // [13,17]
    fancy.append(10); // [13,17,10]
    fancy.multAll(2); // [26,34,20]

    cout << fancy.getIndex(0) << endl; // 26
    cout << fancy.getIndex(1) << endl; // 34
    cout << fancy.getIndex(2) << endl; // 20

    return 0;
}

/*
TC: O(n) for n calls to append, addAll, multAll and getIndex
SC: O(n) for n calls to append, addAll, multAll and getIndex
*/